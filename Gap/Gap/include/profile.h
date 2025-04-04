#pragma once
#include "pch.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/credentials.h"

class Profile {
public:
	Profile();
	void display();

private:
	void editProfile();

	char key; 
	std::string fullName = credentials::firstName + " " + credentials::lastName;
	std::string input = "";

	bool running = true;
};