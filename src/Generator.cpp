#include <vector>
#include <sstream>
#include <random>
#include <stdexcept>
#include "Generator.h"
#include "KGram.h"

Generator::Generator(const KGram& model)
    : model_(model), 
      random_engine_(std::random_device{}()) 
{

}

std::string Generator::generate(int num_chars_to_output)
{
    std::stringstream output_stream;
    std::string current_kgram;

    try {

        current_kgram = this->sampleStartKGram();
    } catch (const std::runtime_error& e) {
        return "Model is empty";
    }

    for (int i = 0; i < num_chars_to_output; i++)
    {
        char next_char;
        try {
            next_char = this ->sampleNextCharacter(current_kgram);
        } catch (const std::runtime_error& e) {
            break;
        }
    output_stream << next_char;

    current_kgram = current_kgram.substr(1) + next_char;
    }

    return output_stream.str();

}

std::string Generator::sampleStartKGram() 
{

    const auto& frequencies = model_.getFrequencies();

    if (frequencies.empty()) {
        throw std::runtime_error("Model hat keine k-Gramm-Frequenzen.");
    }

    std::vector<std::string> kgrams;
    std::vector<double> weights; 


    for (const auto& pair : frequencies) {
        kgrams.push_back(pair.first);  // z.B. "ab"
        weights.push_back(static_cast<double>(pair.second)); // z.B. 2
    }


    std::discrete_distribution<int> distribution(weights.begin(), weights.end());


    int index = distribution(random_engine_);


    return kgrams[index];
}

char Generator::sampleNextCharacter(const std::string& current_kgram) 
{

    const auto& transitions = model_.getTransitions();

 
    auto it = transitions.find(current_kgram);


    if (it == transitions.end() || it->second.empty()) {
        throw std::runtime_error("Sackgasse: " + current_kgram);
    }

    const auto& next_char_map = it->second;

    std::vector<char> possible_chars;
    std::vector<double> weights;

    for (const auto& pair : next_char_map) {
        possible_chars.push_back(pair.first);  // z.B. 'a'
        weights.push_back(static_cast<double>(pair.second)); // z.B. 1
    }

    std::discrete_distribution<int> distribution(weights.begin(), weights.end());


    int index = distribution(random_engine_);

 
    return possible_chars[index];
}