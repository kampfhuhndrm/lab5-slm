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

float KGram::frequency(const string& w)const{
    //Division by zero
    if (total_count_ == 0) {
        return 0.0f;
    }

    auto it = freq_.find(w);

    // 3. Prüfen, ob das k-Gramm überhaupt gefunden wurde
    if (it == freq_.end()) {
        return 0.0f;
    }

    return static_cast<float>(it->second) / static_cast<float>(total_count_);
}

float KGram::P(char c, const std::string& w) const 
{
    // Find n(w)
    auto it_w = freq_.find(w);
    if (it_w == freq_.end()) {
        return 0; 
    }
    int n_w = it_w->second; // n(w)

    // Find n(w, c)
    auto it_trans = transitions_.find(w);
    if (it_trans == transitions_.end()) {
        return 0; 
    }
    
    auto it_char = it_trans->second.find(c);
    if (it_char == it_trans->second.end()) {
        return 0; 
    }
    int n_wc = it_char->second;
    
   // P(c|w) = n(w,c) / n(w) 
    return static_cast<float>(n_wc) / n_w;
}