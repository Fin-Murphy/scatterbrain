#include "term.h"
//trash commit
terminal::terminal(){
	std::vector<std::string> pullSources;
	pullSources.push_back("/Users/owner/Desktop/Vaults/1-PROJECTS/Tasks.md");
	pullSources.push_back("/Users/owner/Desktop/Vaults/0-SCHOOL/Assignments.md");
	
	for(std::string s : pullSources){
		std::ifstream file(s);
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
				Date due;
				ss >> lim;
				ss >> lim;
				while(ss && (wordCount <= maxWords) ){
					std::string word;
					ss >> word;
					if(word[0] == '>'){
						word[0] = ' ';
						std::stringstream dateStream(word);
						dateStream >> due;
					} else {
						task = task + " " + word;
						wordCount++; 
					}
				
				}
				Task T;
				T.name = task;
				T.list = currentList;
				T.dueDate = due;
				tasklist.push_back(T);
			} 
			
			else if(lim == "##"){
				ss >> currentList;
				if(currentList == "COMPLETED"){
					break;
				}
			} 
			
			else if(lim == "***"){
				break;
			}
		}
	}
}


terminal::~terminal(){

}

void terminal::runTime(){
	bool running = true;
	std::cout << "Dashboard - Input commands" << std::endl;
	while(running == true){
		std::string input;
		std::cout << "| > ";
		std::cin >> input;
		if(input == "list"){
			this->listAllTasks();
		} else if(input == "quit"){
			running = false;
		}
	}
}


void terminal::listAllTasks(){

	for(Task T : tasklist){
		std::cout 
		<< "[ ] " << T.dueDate << " "
		<< std::setw(30) << std::left << T.name << std::setw(9) << " | " 
		<< T.list << " |" <<
		std::endl;
	}
}




