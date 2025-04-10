#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/credentials.h"

class Library {
public:
	void display();
	void actionHandler(PageHandler& pages);
private:
		void displayTheme(std::string theme);
	char key;
};