#include <iostream>
#include <string>



void termDisp() {

bool dRun = true;
while(dRun == true){
std::string userInp = "";
std::cout << "Continue? (enter to continue, q to quit): ";
std::cin >> userInp;

if(userInp == "q"){
dRun = false;

}



}


}


int main() {

termDisp();

return 0;

}
