#pragma once
#include "pch.h"
#include "../../DAL/include/files.h"
#include "../../BLL/include/events.h"

class Timeline {
public:
	Timeline();
	void display();


private:
	char key;
	const std::string& filePath = "../../Gap/Data/events.json";
};