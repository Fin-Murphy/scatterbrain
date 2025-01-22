#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <sstream> 
#include <iomanip>
#include <exception>
#include <stdexcept>	

class terminal {
public:
int x;
int y;
void termDisp(); 
std::vector<std::string> fQuery(std::vector<std::string> returnvec);
};


int main() {
terminal mTerm;

std::vector<std::string> valVec = {};
std::vector<std::string> tasks = mTerm.fQuery(valVec);


mTerm.termDisp();


return 0;

}

std::vector<std::string> terminal::fQuery(std::vector<std::string> returnvec) {

	try {

	std::ifstream file ("/storage.txt");
	throw std::invalid_argument("Not a valid arg");
	//std::vector<std::string> returnvec = {};
	std::string line;

		while(std::getline(file,line)) {
			std::stringstream ss(line);
			std::string taskName;
			int taskCval;
			int taskComp;

		}
	}

	catch(...){
		std::cout << "operation failed, creating taskfile" << std::endl;

		std::ofstream file("/storage.txt");

		file << "SPECIFIER:_Base_Tasklist_File" << std::endl;
		file << "1.2.3.4.5" << std::endl;
	
		std::cout << "Wrote in basic file" << std::endl;

    }

return returnvec;

}


void terminal::termDisp() {



	bool dRun = true;
	
	while(dRun == true){

		std::string userInp = "";
		std::cout 
		//<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		//<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		//<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		<< 	" Continue? (enter to continue, q to quit): > ";
		std::cin >> userInp;

		if(userInp == "q"){

			dRun = false;

		} else {}

	}

}

