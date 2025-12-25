#include "toDoList.h"
#include <sstream>

void ToDoList::printTasks(){
    for (Task task : m_tasks){
        std::cout << task.name << " : " << ((task.completed) ? "Done" : "Incomplete") << '\n';
    }
}

void ToDoList::loadTasks(){
    if (m_file.is_open()){
        m_file.ignore(256, '!');
        m_file.ignore(256, '\n');

        for (std::string line [2]; std::getline(m_file, line[0], ' ') && line[0] != ";";){
            m_file.ignore(256, ':');
            m_file.ignore(256, ' ');
            std::getline(m_file, line[1]);

            m_tasks.push_back(Task {line[0], (line[1] == "Done") ? true : false});
        }

    } else {
        //FIXME: error handling
    }
}

void ToDoList::resetFilePointer(){
    m_file.clear();
    m_file.seekg(0);
}

void ToDoList::updateList(){
    std::stringstream ss {};

    ss << "Date: ";
    ss << "N/A"; //FIXME: add actual date
    ss << "\n\n";

    writeTasksToSS(ss);

    ss << ';';

    //FIXME: other stuff further on
}

void ToDoList::writeTasksToSS(std::stringstream& ss){
    for (Task task : m_tasks){
        ss << task.name << " : " << ((task.completed) ? "Done" : "Incomplete") << '\n';
    }
}