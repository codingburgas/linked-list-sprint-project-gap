#include "../include/login.h"
using namespace std;
void Login() {
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