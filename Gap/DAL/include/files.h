#pragma once
#include <string>
#include "../../BLL/include/credentials.h"
#include "../include/pch.h"

void insertRecord(std::string name, std::string lastName, std::string email, std::string password);

bool loginUser(std::string username, std::string email, std::string password);
