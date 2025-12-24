#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

#include <iostream>
#include <vector>

struct Task {
    std::string m_name {};
    bool completed {false};
};

class ToDoList {
    private:
        std::string m_filePath;
        std::vector<Task> m_tasks {};
    
    public:
        ToDoList(std::string filePath)
            : m_filePath {filePath}
        {
            std::cout << m_filePath;
        }

        ToDoList() = delete;
};

#endif