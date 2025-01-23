#include "term.h"




std::vector<Task> terminal::fQuery(std::string strinp) {

	std::vector<Task> returnvec = {};

	try {

	std::ifstream file ("./storage.txt");
	if(!file.is_open()){throw std::invalid_argument("Not a valid arg");}
	//std::vector<std::string> returnvec = {};
	std::string line;

		while(std::getline(file,line)) {
			std::stringstream ss(line);
			std::string taskName;
			int taskCval;
			int taskComp;
            ss >> taskName;
            if(taskName != ">"){
                ss >> taskCval;
                ss >> taskComp;
                Task t;
                t.name = taskName;
                t.cval = taskCval;
                t.comp = taskComp;
                returnvec.push_back(t);
            }
		}
	}

	catch(...){
		std::cout << "operation failed, creating taskfile" << std::endl;

		std::ofstream file("./storage.txt");

		file << "> SPECIFIER:_Base_Tasklist_File" << std::endl;
		file << "> 1.2.3.4.5" << std::endl;
        file << "Task1 0 1" << std::endl;
        file << "Task2 0 1" << std::endl;
        file << "Task3 0 1" << std::endl;
	
		std::cout << "Wrote in basic file" << std::endl;

    }

    

return returnvec;

}


void terminal::termDisp(terminal inpterm) {
	bool dRun = true;
	
	while(dRun == true){

		std::string userInp = "";
		std::cout 
		//<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		//<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		//<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		<< 	" Continue? (enter to continue, q to quit, l to list tasks): > ";
		std::cin >> userInp;

		if(userInp == "q"){

			dRun = false;

		}
		if(userInp == "l"){
			std::vector<Task> ovec = inpterm.fQuery("l");
            for(Task t : ovec){
                std::cout << t.name << std::endl;
            }
		}

	}

}

