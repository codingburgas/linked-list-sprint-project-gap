#include <iostream>
#include "../include/pch.h"
using namespace std;
int main()
{
    int res;
    cout << "=======================\n";
    std::cout << "Gap\n"<<"App for history enthusiasts!\n";
    cout << "=======================\n";
    cout << "Press 'R' to register or 'L' to login: \n";
    char key = _getch();  

    if (key == 'r' || key == 'R') {
        Register();
    }
    else if (key == 'l' || key == 'L') {

    }
    else {
        cout << "\nInvalid key. Try again!\n";
    }
}


