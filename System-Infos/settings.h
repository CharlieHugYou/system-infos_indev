#pragma once

#include <iostream>

// in settings.cpp file
void settingsMenu();

void writeSettings(int goto_menu);
void writeSettingsConfigFirstConnect();

void checkFirstConnection();
void firstConnectProcess();

struct user
{
	std::string name;
	bool canUseAdvancedCommand = false;
};
