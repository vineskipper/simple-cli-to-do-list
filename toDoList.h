#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem> //FIXME: remove later maybe

struct Task {
    std::string name {};
    bool completed {false};
};

class ToDoList {
    private:
        std::filesystem::path m_filePath;
        std::vector<Task> m_tasks {};
        std::ifstream m_file;

        void resetFilePointer();
        void loadTasks();
        void writeTasksTo(std::ostream& outputStream);
        
    public:
        ToDoList(std::filesystem::path filePath)
            : m_filePath {filePath}, m_file {filePath}
        {
            //FIXME: other setup stuff
            loadTasks();
        }

        ToDoList() = delete;
        
        //FIXME: complete destructor
        
        ~ToDoList(){
            updateList();
            //FIXME: other clean up
            m_file.close();
        }

        void printTasks(bool showIndex = false);
        std::stringstream updateList();
        void flipTaskStatus(int taskIndex);
};

#endif