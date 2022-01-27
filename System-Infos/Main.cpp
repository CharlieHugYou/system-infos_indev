#include <iostream>

#include "pass.h"
#include "settings.h"
#include "Main.h"
#include "utilities.h"

void dev();

int main()
{
	dev();

	system("cls");
	/*load();
	checkFirstConnection();*/

	return 0;
}

void start()
{
	menu();
}

void menu()
{
	std::string userInput;

	std::cout << "Menu principale" << std::endl
		<< "| -- > 1. Acceder au menu des commande" << std::endl
		<< "| -- > 2. Parametre" << std::endl
		<< "| -- > 3. Quitte" << std::endl
		<< "Commande rapide : /help" << std::endl;

	std::cin >> userInput;

	if (userInput == "1" || "command")
	{
		command();
	}

	if (userInput == "2" || "set" || "settings" || "parametre")
	{
		writeSettings();
	}

	if (userInput == "3" || "quitte")
	{
		exit(1);
	}

	if (userInput == "/help")
	{
		system("cls");
		help_command("help.data.show");
	}
}

void command()
{
	system("cls");
	std::cout << "Type a command" << std::endl;
}


// pour tester la fonction de test et les autres fonction qui arriveront et que je dois tester en dehors d'un ajout dans un code déjà présent
void dev()
{
	while (true)
	{
		text("test", "red", "stay");
		text("test2", "", "jump-line");
		text("test3", "green", "stay");
		break;
	}
	std::cin.ignore();
}
