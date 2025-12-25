#include "toDoList.h"

//TODO: add an argument parser

// returns choice number
int startMenu(){
    std::cout << "Options\n";

    return 0; //tmp
}

void clearScreen(){
    #ifdef WIN_32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
    std::filesystem::path filePath {};

    do {
        clearScreen();
        std::cout << "Enter the file path of the list you want to use: ";
        std::cin >> filePath;
    } while (!std::filesystem::exists(filePath));
    
    ToDoList list {"exampleList.txt"}; //FIXME: THE FILE DOESN'T COMPILE BECAUSE OF ME
    
    std::cout << "\n\nworking\n\n";
    return 0;
}