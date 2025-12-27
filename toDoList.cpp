#include "toDoList.h"
#include <sstream>

void ToDoList::printTasks(bool showIndex){
    if (showIndex){
        Task task {};

        for (int i {0}; i < m_tasks.size(); i++){
            task = m_tasks.at(i);

            std::cout << i + 1 << ".) " << task.name << " : " << ((task.completed) ? "Done" : "Incomplete") << '\n';
        }

    } else {
        for (Task task : m_tasks){
            std::cout << task.name << " : " << ((task.completed) ? "Done" : "Incomplete") << '\n';
        }
   
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

std::stringstream ToDoList::updateList(){
    std::stringstream oldFileContent {};
    
    for (std::string line {}; std::getline(m_file, line); oldFileContent << '\n'){
        oldFileContent << line;
    }

    m_file.close();

    std::ofstream listFile {m_filePath};

    listFile << "Date: ";
    listFile << "N/A"; //FIXME: add actual date
    listFile << "\n\n!\n";

    writeTasksTo(listFile);

    listFile << ';';

    listFile.close();

    m_file.open(m_filePath);

    //FIXME: other stuff further on

    return oldFileContent;
}

void ToDoList::writeTasksTo(std::ostream& outputStream){
    for (Task task : m_tasks){
        outputStream << task.name << " : " << ((task.completed) ? "Done" : "Incomplete") << '\n';
    }
}