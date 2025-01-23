

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

//#include "term.h"

class terminal {
public:
int x;
int y;
void termDisp(terminal inpterm); 
std::vector<std::string> fQuery();
};


#endif