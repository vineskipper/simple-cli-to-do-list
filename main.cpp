#include <iostream>
#include <fstream>
#include <iomanip> // for std::quoted
#include <sstream>

// prints the contents of a string stream
void printSS(std::stringstream& stream){
    for (std::string line {}; std::getline(stream, line); std::cout << '\n'){
        std::cout << line;
    }
}

// copies the contents of an ifstream to a sstream
void copy(std::ifstream& input, std::stringstream& output){
    for (std::string line {}; std::getline(input, line); output << '\n'){
        output << line;
    }
}

int main(int argc, char* argv[]){
    const std::string filePath {argv[1] ? argv[1] : "config.txt"};

    std::ifstream inputFile {filePath};
    std::stringstream outputContent {};

    //FIXME: move to class file
    if (inputFile.is_open()){
        for (std::string line[2] {}; std::getline(inputFile, line[0], ':'); outputContent << '\n'){
            std::getline(inputFile, line[1]);
            outputContent << line[0] << "::" << line[1];
        }

        printSS(outputContent);

    } else std::cout << std::quoted(filePath) << " was not found.";

    return 0;
}