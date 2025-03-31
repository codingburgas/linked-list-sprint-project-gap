#pragma once
#include "../include/pch.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/register.h"
#include "../../BLL/include/credentials.h"

class Register {
public:
	Register();
	void checkAndInsertCreds();
	void display();

private:

};
