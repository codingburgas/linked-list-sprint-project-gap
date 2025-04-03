#include "../include/dashboard.h"

 Dashboard::Dashboard() {
	 Dashboard::display();
}

 
 void Dashboard::display() {
	 system("CLS");
	 std::cout << "Hey, " << credentials::firstName << " " << credentials::lastName;

 }