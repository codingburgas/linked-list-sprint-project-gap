#pragma once
#include "pch.h"
#include "pageHandler.h"

class Menu {
public:
	void display();
	void actionHandler(PageHandler& pages);

private:
	char key;
	const int height = 7;
	const int width = 7;
	const int spacing = 2;
	const int textWidth = width * 3 + spacing * 2;
	const int verticalHeight = 3;
	const int horizontalWidth = 7;
};
