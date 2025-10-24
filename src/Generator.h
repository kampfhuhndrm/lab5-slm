#include <string>
#include <random> 
#include "KGram.h" 

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