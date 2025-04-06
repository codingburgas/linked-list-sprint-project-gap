#include "../include/dashboard.h"

 void Dashboard::display() {
	 system("CLS");
     std::cout << "===================================" << std::endl;
	 std::cout << "  Hey, " << credentials::firstName << " " << credentials::lastName<<"!" << std::endl;
     std::cout << "===================================" << std::endl;
     std::cout << "|       Ready for knowledge?      |"<< std::endl;
     std::cout << "| [P] Profile                     |\n";
     std::cout << "| [S] Search                      |\n";
     std::cout << "| [L] Library                     |\n";
     std::cout << "| [T] Timeline                    |\n";
     std::cout << "| [C] Create New Event            |\n";
     std::cout << "| [E] Log Out                     |\n";
     std::cout << "===================================" << std::endl;
 }

 void Dashboard::actionHandler(PageHandler& pages) {
     while (true) {
         key = _getch();

         if (tolower(key) == 'p') {
            pages.profilePageShouldDisplay = true; 
            pages.dashboardPageShouldDisplay = false; 
            break;
         }
         else if (tolower(key) == 's') {
             break;

         }
         else if (tolower(key) == 'l') {
             pages.libraryPageShouldDisplay = true;
             pages.dashboardPageShouldDisplay = false;
             break;
         }
         else if (tolower(key) == 't') {
             pages.timelinePageShouldDisplay = true;
             pages.dashboardPageShouldDisplay = false;
             break;
         }
         else if (tolower(key) == 'c') {
             pages.createEventPageShouldDisplay = true;
             pages.dashboardPageShouldDisplay = false;
             break;
         }
         else if (tolower(key) == 'e') {
			 credentials::username = "";
			 credentials::firstName = "";
			 credentials::lastName = "";    
			 credentials::email = "";
			 credentials::password = "";
             pages.menuPageShouldDisplay = true;
             pages.dashboardPageShouldDisplay = false;
             break;
         }
         else if(tolower(key) != '\n') {
             std::cout << "\n Invalid key. Try again: ";
             continue;
         }
     }
 }