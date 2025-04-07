#pragma once
#include "pch.h"
#include "../../DAL/include/files.h"
#include "pageHandler.h"

class Search {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	void searchByTheme();
	void searchByDate();
	void searchByLocation();

	char key;
	std::string input;
};
