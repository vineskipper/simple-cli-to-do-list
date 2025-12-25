#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

#include <iostream>
#include <vector>
#include <fstream>

struct Task {
    std::string name {};
    bool completed {false};
};

class ToDoList {
    private:
        std::string m_filePath;
        std::vector<Task> m_tasks {};
        std::ifstream m_file;

        void resetFilePointer();
        
    public:
        ToDoList(std::string filePath)
            : m_filePath {filePath}, m_file {filePath}
        {
            // other setup stuff
        }

        ToDoList() = delete;

        void printTasks();
        void loadTasks(); //FIXME: I SHOULD BE A PRIVATE MEMBER FUNCTION
};

#endif