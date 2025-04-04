#pragma once
#include <string>
#include "../include/pch.h"

void insertRecord(std::string username, std::string firstName, std::string lastName, std::string email, std::string password);

bool loginUser(std::string username, std::string email, std::string password, std::string firstName, std::string lastName);
