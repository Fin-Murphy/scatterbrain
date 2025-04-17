#include "term.h"

terminal::terminal(){

std::ifstream file("/Users/owner/Desktop/Vaults/1-PROJECTS/Tasks.md");
std::string line;
std::string lim;
std::string word;

	while(std::getline(file,line)){
		std::stringstream ss(line);
		ss >> lim;

		if(lim == "-"){
			std::string task = "";
			ss >> lim;
			ss >> lim;
			while(ss){
				ss >> word;
				task = task + word; 
			}
			Task T;
			T.name = task;
			tasklist.push_back(T);
		}

	}
		
}
