#pragma once
#include "pageHandler.h"
#include "pch.h"
#include "register.h"
#include "login.h"
#include "menu.h"
#include "dashboard.h"
#include "profile.h"
#include "timeline.h"
#include "library.h"
#include "createEvent.h"
#include "search.h"

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
	Library library;
	CreateEvent createEvent;
	Search search;
	PageHandler pages;

	bool running = true;
};