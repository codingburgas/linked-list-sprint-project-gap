#include "../include/pageHandler.h"

PageHandler::PageHandler() {
    exitApp = false;
    menuPageShouldDisplay = true;
    registerPageShouldDisplay = false;
    loginPageShouldDisplay = false;
    dashboardPageShouldDisplay = false;
    profilePageShouldDisplay = false;
    timelinePageShouldDisplay = false;
    createEventPageShouldDisplay = false;
}

PageHandler pages;