

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
    std::string name;
    int cval;
    int comp;
};



//#include "term.h"

class terminal {
public:
int x;
int y;
void termDisp(terminal inpterm); 
std::vector<Task> fQuery(std::string strinp);
};


#endif