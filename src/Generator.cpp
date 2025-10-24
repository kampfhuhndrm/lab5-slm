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
