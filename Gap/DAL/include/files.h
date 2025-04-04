#pragma once
#include <string>
#include "../../BLL/include/credentials.h"
#include "../include/pch.h"
#include "../../Gap/include/dashboard.h"

bool loginUser(std::string username, std::string email, std::string password);

void insertRecord(std::string username, std::string firstName, std::string lastName, std::string email, std::string password);

