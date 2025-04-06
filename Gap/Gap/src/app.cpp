#include "../include/app.h"

App::App() {
	while(running){
		pageHandler();
	}
}

void App::pageHandler() {
	if (pages.menuPageShouldDisplay) {
		menu(pages);
		return;
	}
	if (pages.registerPageShouldDisplay) {
		reg.display(pages);
		return;
	}
	if (pages.loginPageShouldDisplay) {
		login.display(pages);
		return;
	}
	if (pages.dashboardPageShouldDisplay) {
		dash.display();
		dash.actionHandler(pages);
		return;
	}
	if (pages.profilePageShouldDisplay) {
		profile.display();
		profile.actionHandler(pages);
		return;
	}
	if (pages.timelinePageShouldDisplay) {
		timeline.display();
		timeline.actionHandler(pages);
	}
	if (pages.libraryPageShouldDisplay) {
		library.display();
		library.actionHandler(pages);
	}
	if (pages.exitApp) {
		running = false;
		return;
	}
}