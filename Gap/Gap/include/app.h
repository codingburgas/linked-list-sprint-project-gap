#pragma once
#include "pageHandler.h"
#include "pch.h"
#include "register.h"
#include "login.h"
#include "menu.h"
#include "dashboard.h"
#include "profile.h"
#include "timeline.h"
#include "createEvent.h"

class App {
public:
	App();

private:
	void pageHandler();
	Menu menu;
	Login login;
	Register reg;
	Profile profile;
	Dashboard dash; 
	Timeline timeline;
	CreateEvent createEvent;
	PageHandler pages;

	bool running = true;
};