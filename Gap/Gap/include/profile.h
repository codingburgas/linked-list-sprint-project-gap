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
	void editCredentials();

};