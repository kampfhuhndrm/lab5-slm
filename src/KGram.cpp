#include <string>
#include <iostream>
#include "KGram.h"
#include <fstream>
#include <sstream>
using namespace std;

KGram::KGram(const string& filename, int k)
{
    k_ = k;
    std::ifstream file(filename);
    if(!file.is_open()){
        throw std::runtime_error(filename+"couldnt be opened");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();

    file.close();

    if(content.length() <= k_){
        return;
    }

    for(size_t i=0; i < content.length() - k_;i++){
        string kgram = content.substr(i, k_);

        char next_char = content[i + k_];

        freq_[kgram]++;
        transitions_[kgram][next_char]++;
        total_count_++;
    }

}

float KGram