#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/credentials.h"

class Dashboard {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	char key;
};