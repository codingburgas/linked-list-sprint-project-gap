#include "../include/login.h"
using namespace std;
Login::Login() {
	Login::display();
}


void Login::display() {
	system("CLS");
	string email, pass;
	cout << "Welcome back to Gap!\n";
	cout << "Email: ";
	cin >> email;
	while (!checkEmail(email)) {
		cout << "Input valid email!" << endl;
		cout << "Email: ";
		cin >> email;
	}
	cout << "Password: ";
	cin >> pass;
	while (!checkPassword(pass)) {
		cout << "Invalid password!" << endl;
		cout << "Password: ";
		cin >> pass;
	}
	
	

}
void Login::checkCreds() {

}