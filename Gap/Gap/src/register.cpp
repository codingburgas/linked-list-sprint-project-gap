#include "../include/register.h"
using namespace std;
void Register() {
	system("CLS");
	string name, lastName, email, pass;
	cout << "Welcome to Gap!\n" << "First name: ";
	cin >> name;
	cout << "Last name: ";
	cin >> lastName;
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
	while(!checkEmail(email) && !checkPassword(pass)){}
	if (!checkEmail(email) && !checkPassword(pass)) cout << "Invalid credentials!" << endl;
}