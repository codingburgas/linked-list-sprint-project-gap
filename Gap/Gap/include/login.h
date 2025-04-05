#pragma once
#include "pch.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/register.h"
#include "../../BLL/include/credentials.h"
#include "pageHandler.h"

class Login {
public:
	void display(PageHandler& pages);
	void inputCreds();
	void checkCreds();

private:
};
