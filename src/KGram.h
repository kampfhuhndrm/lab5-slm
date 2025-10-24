#include <iostream>
#include <string>
#include <map>


class KGram 
{
    public:
    // load file
    KGram(const std::string& filename, int k);
    
    //Frequency
    float frequency(const std::string& w) const;
    //propability distribution
    float P(char c, const std::string& w) const; 
    const std::map<std::string, int>& getFrequencies() const { 
        return freq_; 
    }
    const std::map<std::string, std::map<char, int>>& getTransitions() const { 
        return transitions_; 
    }

    private:
    int k_;
    std::map<std::string, int> freq_;                      // n(w)
    std::map<std::string, std::map<char, int>> transitions_; // n(w, c)
    int total_count_; // total number of k-grams

};