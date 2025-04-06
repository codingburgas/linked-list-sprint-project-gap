#pragma once
#include "pch.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/events.h"
#include "pageHandler.h"

class Timeline {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	char key;
	const std::string& filePath = "../../Gap/Data/events.json";
};