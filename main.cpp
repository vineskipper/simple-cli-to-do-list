#include "toDoList.h"
#include <thread> // for sleep_for
#include <chrono> // for time unit object types
//TODO: add an argument parser

namespace global{
    const std::string options[] {"List tasks", "Change a task's status"};
}

// clears the console after "waitTime" seconds
void clearScreen(int waitTime = 0.5){
    std::this_thread::sleep_for(std::chrono::milliseconds(waitTime * 100));

    #ifdef WIN_32
        system("cls");
    #else
        system("clear");
    #endif
}

int startMenu(){
    clearScreen(0);
    std::cout << "Options:\n";

    for (int i {0}; i < (sizeof(global::options) / sizeof(std::string)); i++){
        std::cout << i + 1 << ".) " << global::options[i] << '\n';
    }

    int choice {};
    std::cout << "\nEnter an option number: ";
    std::cin >> choice;

    return choice;
}

int main(){
    std::filesystem::path filePath {};

    do { //FIXME: add an error message
        clearScreen();
        std::cout << "Enter the file path of the list you want to use: ";
        std::cin >> filePath;

    } while (!std::filesystem::exists(filePath));
    
    ToDoList list {filePath};
    startMenu();
    
    return 0;
}