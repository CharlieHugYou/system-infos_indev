#include <iostream>
#include <fstream>

#include "pass.h"
#include "settings.h"
#include "Main.h"
#include "utilities.h"

void dev();

int main()
{
	//dev();

	system("cls");
	load();
	checkFirstConnection();

	return 0;
}

void start()
{
	menu();
}

void menu()
{
	std::string userInput;

	while (true)
	{
		std::cout << "Menu principale" << std::endl
			<< "| -- > 1. Acceder au menu des commandes" << std::endl
			<< "| -- > 2. Parametre" << std::endl
			<< "| -- > 3. Quitte" << std::endl
			<< "Commande rapide : /help" << std::endl;

		std::cin >> userInput;

		if (userInput == "1")
		{
			command();
			continue;
		}

		if (userInput == "2")
		{
			system("cls");
			settingsMenu();
			continue;
		}

		if (userInput == "3")
		{
			exit(1);
		}

		if (userInput == "/help")
		{
			system("cls");
			help_command("help.data.show");
			continue;
		}
	}
}

void command()
{
	user user;

	std::string userCommand;

	std::ifstream read_user_name_file("user.data");

	read_user_name_file >> user.name;

	system("cls");
	while (true)
	{
		std::cout << "Menu principal -> Commande/" << user.name << ": ";
		std::cin >> userCommand;

		if (userCommand == "menu")
		{
			// retourne au menu
			break;
		}
	}

}

void dev()
{
	write_logs("test");
	read_logs();
	
	std::cin.ignore();
}
