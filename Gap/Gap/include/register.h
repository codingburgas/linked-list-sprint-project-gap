#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/register.h"
#include "../../BLL/include/credentials.h"

class Register {
public:
	void display(PageHandler& pages);

private:
	void checkAndInsertCreds();
};
