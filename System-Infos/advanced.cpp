// en dév


#include "advanced.h"
#include "utilities.h"
#include "settings.h"

#include <iostream>
#include <fstream>

void activate()
{
	user user;

	std::string userInput;
	text("Pour acceder a toutes les commmandes de System-Infos, tu dois activer toutes les commandes", "white", "jump-line");
	text("Ecris active pour active toutes les commandes", "write", "jumpe-line");

	std::cin >> userInput;

	if (userInput == "active")
	{
		std::ofstream read_user_file("user.data");

		read_user_file << user.name << "\n" << "true";
	}
}

/*
	si je fais un truc pour avoir le userName, c'est pour pouvoir écrire l'activation des commandes avancé 
	et ne prendre en compte le userName
*/
