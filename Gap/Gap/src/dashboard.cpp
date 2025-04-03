#include "../include/dashboard.h"

 Dashboard::Dashboard() {
	 Dashboard::display();
}

 
 void Dashboard::display() {
	 system("CLS");
     std::cout << "===============================" << std::endl;
	 std::cout << "Hey, " << credentials::firstName << " " << credentials::lastName<<"!" << std::endl;
     std::cout << "===============================" << std::endl;
     std::cout << "Ready for knowledge? "<< std::endl;
     char key;
     std::cout << "Type 'P' to open Profile"<<std::endl<<"Type 'S' to open Search" << std::endl << "Type 'L' to open Library" << std::endl << "Type 'T' to open Timeline" << std::endl << "Type 'C' to Create new event";
     while (true) {
         key = _getch();
         if (tolower(key) == 'p') {
             break;
         }
         else if (tolower(key) == 's') {
             break;
         }
         else if (tolower(key) == 't') {
             break;
         }
         else if (tolower(key) == 'c') {
             break;
         }
         else {
             std::cout << "\nInvalid key. Try again!";
         }
     }
 }