#pragma once
#include <string>
#include "pch.h"
#include "../../BLL/include/credentials.h"
#include "../../Gap/include/dashboard.h"

using nlohmann::ordered_json;
using json = nlohmann::json;

bool loginUser(std::string username, std::string email, std::string password);

void insertRecord(std::string username, std::string firstName, std::string lastName, std::string email, std::string password);

void editUserInfo(std::string username, std::string firstName, std::string lastName, std::string email, std::string password);

ordered_json fetchEventsFromJSON(const std::string& filePath);

void createEvent(std::string eventName, 
	std::string date, 
	std::string endDate, 
	std::string description, 
	std::string createdBy, 
	std::string leader, 
	std::string theme, 
	std::string casualties, 
	std::vector<std::string> participants,
	std::string location);