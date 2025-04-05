#pragma once
#include <string>
#include "../include/pch.h"
#include "../../BLL/include/credentials.h"
#include "../../Gap/include/dashboard.h"
#include "../../BLL/include/events.h"
bool loginUser(std::string username, std::string email, std::string password);

void insertRecord(std::string username, std::string firstName, std::string lastName, std::string email, std::string password);

void editUserInfo(std::string username, std::string firstName, std::string lastName, std::string email, std::string password);

void displayEvents();

