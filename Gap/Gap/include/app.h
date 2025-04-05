#pragma once
#include "pageHandler.h"
#include "pch.h"
#include "register.h"
#include "login.h"
#include "menu.h"
#include "dashboard.h"
#include "profile.h"

class App {
public:
	App();

private:
	void pageHandler();
	Login login;
	Register reg;
	Profile profile;
	Dashboard dash; 
	PageHandler pages;

	bool running = true;
};