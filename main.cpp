#include <iostream>
#include <string>

class terminal {
public:
int x;
int y;
void termDisp(); 
};



int main() {

terminal mTerm;

mTerm.termDisp();

return 0;

}



void terminal::termDisp() {

	bool dRun = true;
	
	while(dRun == true){

		std::string userInp = "";
		std::cout 
		<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		<< 	" Continue? \n  (enter to continue, q to quit): > " << 
		std::endl;
		std::cin >> userInp;

		if(userInp == "q"){

			dRun = false;

		} else {}



	}


}

