#include <iostream>

#include "pass.h"
#include "settings.h"
#include "Main.h"

int main()
{
	checkFirstConnection();

	return 0;
}

void start()
{
	std::cout << "Start function" << std::endl;
	menu();
}

void menu()
{
	std::string str;
	std::cin >> str;
	std::cout << str;
}