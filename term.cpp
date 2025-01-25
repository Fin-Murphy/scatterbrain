#include "term.h"

terminal::terminal() {

	std::ifstream file ("./storage.txt");
	if(!file.is_open()){
		std::cout << "\033[31m\n| > OPERATION FAILED! \n| > CREATING TASKFILE.\n| > FILE CREATED!\033[0m ATTEMPT OPERATION AGAIN \n" << std::endl;
		std::ofstream ofile("./storage.txt");
		ofile << "> SPECIFIER:_Base_Tasklist_File" << std::endl;
		ofile << "> 1.2.3.4.5" << std::endl;
        ofile << "Task1 0 1\nTask2 0 1\nTask3 0 1" << std::endl;
		std::ifstream file ("./storage.txt");

	}
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
			this->tasklist.push_back(t);
		}
	}

}

void terminal::termDisp() {

    std::cout << "\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n";

	bool dRun = true;
	
	while(dRun == true){

		std::string userInp = "";
		std::cout << 	"| inCursor >  | ";
		std::cin >> userInp;
        if(userInp == "help"){
            std::cout << "|\n| > 'quit' to quit program\n| > 'list' to list tasks\n";
        }
		else if(userInp == "quit"){
			des();
            std::cout << "\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n";

			dRun = false;

		}
		else if(userInp == "list"){
            for(Task t : this->tasklist){
                std::cout << t.name << std::endl;
            }
		} else if(userInp == "strike"){
			std::string tID = "";
			//std::cout << "| Task name to mark as completed > ";
			std::cin >> tID;
			int itr = 0;
			for(Task t : this->tasklist){
				if(t.name == tID){
					this->tasklist.erase(this->tasklist.begin() + itr);
				} else {itr++;}
			}
			


		} else {std::cout << "\n| > \033[31mCommand unrecognized!\033[0m \n|" << std::endl;}
		

	}

}

void terminal::des() {


for(Task t : this->tasklist){

	std::ofstream ofile("./storage.txt");
		ofile << "> OVERWRITE" << std::endl;
		ofile << "> OVERWRITE" << std::endl;
        ofile << "> OVERWRITE" << std::endl;



}




}
