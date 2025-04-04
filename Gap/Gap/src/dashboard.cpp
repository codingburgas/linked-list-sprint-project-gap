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
     std::cout << "| [P] Profile                     |\n";
     std::cout << "| [S] Search                      |\n";
     std::cout << "| [L] Library                     |\n";
     std::cout << "| [T] Timeline                    |\n";
     std::cout << "| [C] Create New Event            |\n";
     while (true) {
         key = _getch();
         switch (tolower(key)) {
         case 'p': Profile(); break;
         case 's':  break;
         case 'l':  break;
         case 't':  break;
         case 'c':  break;
         default:
             std::cout << "\n Invalid key. Try again: ";
             continue;
         }
     }
 }