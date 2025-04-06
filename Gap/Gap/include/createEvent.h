#pragma once
#include "pch.h"
#include "pageHandler.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/credentials.h"

class CreateEvent {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	void inputEventInfo();
	std::string eventName, date, endDate, description;
	std::string leader, theme, casualties, location;
	std::vector<std::string> participants;
	std::string input;

	char key;
};
