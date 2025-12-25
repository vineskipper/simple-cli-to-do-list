#include "toDoList.h"

void ToDoList::printTasks(){
    for (Task task : m_tasks){
        std::cout << task.name << ((task.completed)? "Done" : "Incomplete") << '\n';
    }
}

void ToDoList::loadTasks(){
    if (m_file.is_open()){
        char array [256];

        m_file.getline(array, sizeof(array) / sizeof(char), '!');

        std::string str {};

        std::getline(m_file, str);

        std::cout << str;

    } else {
        //FIXME: error handling;
    }
}

void ToDoList::resetFilePointer(){
    m_file.clear();
    m_file.seekg(0);
}