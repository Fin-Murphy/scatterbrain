#include "termDisp.h"
using namespace std;

void terminal::termDisp() {

	bool dRun = true;
	
	while(dRun == true){

		std::string userInp = "";
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Continue? \n  (enter to continue, q to quit):\n > " << 
		std::endl;
		std::cin >> userInp;

		if(userInp == "q"){

			dRun = false;

		} else {}



	}


}

