// en dév


#include "advanced.h"
#include "utilities.h"
#include "settings.h"

#include <iostream>
#include <fstream>
#include <string>

void activate()
{
	user user;

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

	std::string userInput;
	text("Pour acceder a toutes les commmandes de System-Infos, tu dois activer toutes les commandes", "white", "jump-line");
	text("Ecris [active] pour activer toutes les commandes ou [desactive]", "write", "jumpe-line");

	std::cout << "Menu principal -> Command/Advanced" << user.name << ": ";


	std::cin >> userInput;

	if (userInput == "active")
	{

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
				break;
			}
		}

		std::ofstream write_user_file("user.data");

		user.name = stored_user_file_content;

		write_user_file << user.name << "\n" << "true";
	}

	
}

void verifAdvancedActived()
{
	user user;

	std::ifstream user_data_file("user.data");

	std::string stored_content_file;

	while (std::getline(user_data_file, stored_content_file))
	{
		if (stored_content_file == user.name)
		{
			continue;
		}
		else if (stored_content_file == "true")
		{
			text("Commande avancer deja activer", "white", "jump-line");
		}
		else if (stored_content_file == "false")
		{
			activate();
		}
	}
}
