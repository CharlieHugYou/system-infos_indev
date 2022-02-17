#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include "pass.h"
#include "settings.h"
#include "Main.h"
#include "utilities.h"
#include "advanced.h"

void dev();

int main()
{
	// dev();

	system("cls");
	load();
	checkFirstConnection();

	return 0;
}

void menu()
{
	user user;

	std::string userInput;

	std::ifstream read_user_name_file("user.data");

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
	std::string stored_user_file_content;

	while (std::getline(read_user_name_file, stored_user_file_content))
	{
		if (stored_user_file_content == "true")
		{
			continue;
		}
		else if (stored_user_file_content == "false")
		{
			continue;
		}
		else
		{
			user.name = stored_user_file_content;
		}
	}


	system("cls");
	while (true)
	{
		std::cout << "Menu principal -> Commande/" << user.name << ": ";
		std::getline(std::cin, userCommand);
		std::cout << std::endl;

		if (userCommand == "help")
		{
			system("cls");
			help_command("help_command.data.show");
			continue;
		}

		if (userCommand == "clear")
		{
			system("cls");
			continue;
		}

		if (userCommand == "logs")
		{
			read_logs();
		}

		if (userCommand == "version -list")
		{
			text("Liste des versions sortie", "white", "jumpe-line");
			text("| -- > Version : dev-0.1", "white", "jump-line");
		}
		if (userCommand == "version -launch")
		{
			text("Version : dev-0.1", "white", "jump-line");
		}
		if (userCommand == "version -infos")
		{
			text("Ferme le fichier pour continue d'utiliser le programme", "red", "jump-line");
			system("changelogs.txt");
		}

		if (userCommand == "discord")
		{
			text("Lien de mon discord : https://discord.gg/6FgmgHkDv6", "white", "jump-line");
		}

		if (userCommand == "advanced -activate")
		{
			std::string advanceCommand;

			while (std::getline(read_user_name_file, advanceCommand))
			{
				if (advanceCommand == user.name)
				{
					continue;
				}
				else if (advanceCommand == "true")
				{
					text("Les commandes avancer sont deja activer", "white", "jump-line");
				}
			}
		}

		if (userCommand == "menu")
		{
			// retourne au menu
			break;
		}
	}

}

void dev()
{
	std::cin.ignore();
}
