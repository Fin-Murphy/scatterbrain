

#ifndef __TERM_H__
#define __TERM_H__

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <sstream> 
#include <iomanip>
#include <exception>
#include <stdexcept>

struct Task {
    std::string name = "Task_";
    int val_needed = 0;
    int current_val = 0;
    std::string list = "Basic_Task";
};

class terminal {

    public:
    std::vector<Task> tasklist;

    terminal();
    ~terminal();

    void termDisp(); 
    void write();
    void list();
    void strike();
    void help();
};


#endif