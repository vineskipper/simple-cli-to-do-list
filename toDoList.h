#ifndef TO_DO_LIST
#define TO_DO_LIST

#include <iostream>
#include <vector>

class ToDoList {
    private:
        std::string m_filePath;
        std::vector<std::string [2]> m_tasks {};
    
    public:
        ToDoList(std::string filePath)
            : m_filePath {filePath}
        {
            std::cout << m_filePath;
        }

        ToDoList() = delete;
};

#endif