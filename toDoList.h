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
        void loadTasks();
        void writeTasksToSS(std::stringstream& out);
        
    public:
        ToDoList(std::string filePath)
            : m_filePath {filePath}, m_file {filePath}
        {
            //FIXME: other setup stuff
            loadTasks();
        }

        ToDoList() = delete;

        ~ToDoList(){
            updateList();
            //FIXME: other clean up
            m_file.close();
        }

        void printTasks();
        void updateList();
};

#endif