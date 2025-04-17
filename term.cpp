#include "term.h"

terminal::terminal(){

	std::ifstream file("/Users/owner/Desktop/Vaults/1-PROJECTS/Tasks.md");
	std::string line;
	std::string lim;
	int wordCount = 0;
	int maxWords = 15;
	std::string currentList;

	while(std::getline(file,line)){
		std::stringstream ss(line);
		ss >> lim;

		if(lim == "-"){
			wordCount = 0;
			std::string task = "";
			ss >> lim;
			ss >> lim;
			while(ss && (wordCount <= maxWords) ){
				std::string word;
				ss >> word;
				task = task + " " + word;
				wordCount++; 
			}


			Task T;
			T.name = task;
			T.list = currentList;
			tasklist.push_back(T);
		} else if(lim == "##"){

			ss >> currentList;
			if(currentList == "COMPLETE"){
				break;
			}
		} else if(lim == "***"){
			break;
		}

	}
		
}
//Testing 1212


terminal::~terminal(){



	std::cout << "Exiting the program" << std::endl;


}