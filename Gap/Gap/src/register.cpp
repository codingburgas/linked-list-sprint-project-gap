#include "../include/pch.h"
using namespace std;

void Register() {
    system("CLS");
    string name, lastName, email, password;
    cout << "Welcome to Gap!\n" << "First name: ";
    getline(cin, name);
	while (name.empty()) {
		cout << "First name cannot be empty!\n";
		cout << "First name: ";
		getline(cin, name);
	}
    cout << "Last name: ";
    getline(cin, lastName);
    while (lastName.empty()) {
        cout << "Last name cannot be empty!\n";
        cout << "Last name: ";
        getline(cin, lastName);
    }
    cout << "Email: ";
    getline(cin, email);
    while (!checkEmail(email)) {
        cout << "Input valid email!\n";
        cout << "Email: ";
        getline(cin, email);
    }
    cout << "Password: ";
    getline(cin, password);
    while (!checkPassword(password)) {
        cout << "Invalid password!\n";
        cout << "Password: ";
        getline(cin, password);
    }
    while(!checkEmail(email) && !checkPassword(password)){ }
    if (!checkEmail(email) && !checkPassword(password)) cout << "Invalid credentials!\n";
    else insertRecord(name, lastName, email, password);
}

