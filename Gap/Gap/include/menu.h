#pragma once
#include "pch.h"

class Menu {
public:
	Menu();
	void display();
	void actionHandler();

private:
	const int height = 7;
	const int width = 7;
	const int spacing = 2;
	const int textWidth = width * 3 + spacing * 2;
	const int verticalHeight = 3;
	const int horizontalWidth = 7;
};