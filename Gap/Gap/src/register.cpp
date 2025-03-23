#include "../include/register.h"
using namespace std;

void Register() {
    system("CLS");
    string name, lastName, email, password;
    cout << "Welcome to Gap!\n" << "First name: ";
    getline(cin, name);
    cout << "Last name: ";
    getline(cin, lastName);
    cout << "Email: ";
    getline(cin, email);
    while (!checkEmail(email)) {
        cout << "Input valid email!" << endl;
        cout << "Email: ";
        getline(cin, email);
    }
    cout << "Password: ";
    getline(cin, password);
    while (!checkPassword(password)) {
        cout << "Invalid password!" << endl;
        cout << "Password: ";
        getline(cin, password);
    }
    while(!checkEmail(email) && !checkPassword(password)){}
    if (!checkEmail(email) && !checkPassword(password)) cout << "Invalid credentials!" << endl;
}