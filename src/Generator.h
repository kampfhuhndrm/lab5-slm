#pragma once // Guter Stil, um doppelte Einbindung zu verhindern

#include <string>
#include <random> // Wichtig für das Sampling [cite: 45]
#include "KGram.h" // Du hattest das schon korrekt

class Generator
{
public:
    Generator(const KGram& model);

    std::string generate(int num_chars_to_output); 

private:
    const KGram& model_; 
    std::mt19937 random_engine_; 

    std::string sampleStartKGram(); 

    char sampleNextCharacter(const std::string& current_kgram);
};