#include <iostream>
#include <string>
#include <stdexcept> 


#include "KGram.h"
#include "Generator.h"


int main(int argc, char* argv[]) 
{

    int k;
    std::string filename;
    int num_chars_to_output;

 
    if (argc != 4) {
        
        std::cerr << "Fehler: Falsche Anzahl an Argumenten." << std::endl;
        std::cerr << "Benutzung: " << argv[0] << " <k> <dateiname> <anzahl_zeichen>" << std::endl;
        std::cerr << "Beispiel:  " << argv[0] << " 2 my_text.txt 100" << std::endl;
        return 1; 
    }


    try {

        k = std::stoi(argv[1]); 
        filename = argv[2]; 
        num_chars_to_output = std::stoi(argv[3]); 
    } 
    catch (const std::invalid_argument& e) {

        std::cerr << "Fehler: 'k' und 'anzahl_zeichen' müssen gültige Zahlen sein." << std::endl;
        return 1; 
    }


    try {
   
        KGram model(filename, k);


        Generator generator(model);


        std::string output = generator.generate(num_chars_to_output);


        std::cout << output << std::endl;

    } 
    catch (const std::runtime_error& e) {

        std::cerr << "Ein Laufzeitfehler ist aufgetreten: " << e.what() << std::endl;
        return 1; 
    }


    return 0; 
}
