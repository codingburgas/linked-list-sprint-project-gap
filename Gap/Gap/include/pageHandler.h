#pragma once

class PageHandler {
public:
    PageHandler();
    bool exitApp;
    bool menuPageShouldDisplay;
    bool registerPageShouldDisplay;
    bool loginPageShouldDisplay;
    bool dashboardPageShouldDisplay;
    bool profilePageShouldDisplay;
    bool timelinePageShouldDisplay;
    bool libraryPageShouldDisplay;
    bool createEventPageShouldDisplay;
	bool searchPageShouldDisplay;
};