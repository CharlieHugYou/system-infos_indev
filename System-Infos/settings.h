#pragma once

#include <iostream>

// in settings.cpp file
void settingsMenu();

void writeSettings(int goto_menu);
void writeSettingsConfigFirstConnect();

void readSettingsFile();

void checkFirstConnection();
void firstConnectProcess();

struct user
{
	std::string name;
};

// in sreen-loader.cpp file
void load();
