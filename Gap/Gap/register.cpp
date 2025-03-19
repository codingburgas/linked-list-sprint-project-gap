#include "pch.h"
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

	cout << "Password: ";
	cin >> pass;
	int size = pass.size();
	bool upper = false, special = false;
	for (int i = 0; i < size; i++) {
		if (isupper(pass[i])) upper = true;
		
	}
}