#include "settings.h"
#include "Main.h"

#include <iostream>
#include <fstream>
#include <Windows.h>

void writeSettings()
{
	std::ofstream logs_fstream("logs.set");
	std::ofstream logs_send_fstream("logs-notif.send.set");

	std::cout << "Menu des parametres" << std::endl
		<< "  1. Logs	2. Affichage" << std::endl;

	std::string userInput;

	std::cin >> userInput;

	if (userInput == "1" || "logs" || "Logs")
	{
		userInput = "";
		system("cls");

		std::cout << "1. Activation des logs	2. Notification des logs" << std::endl;

		userInput = "";
		std::cin >> userInput;

		if (userInput == "1")
		{

			std::cout << "Activer l'ecriture des logs dans le fichier logs.txt ? [oui] [non] : ";

			userInput = "";
			std::cin >> userInput;

			if (userInput == "oui" || "Oui")
			{
				logs_fstream << "on" << std::endl;
			}
			else if (userInput == "non" || "Non")
			{
				logs_fstream << "off" << std::endl;
			}
		}

		if (userInput == "2")
		{
			std::cout << "Activer l'envoie de notifications pour certaines logs importante ? [oui] [non] : ";

			std::cin >> userInput;

			if (userInput == "oui" || "Oui")
			{
				logs_send_fstream << "on" << std::endl;
			}
			else if (userInput == "non" || "Non")
			{
				logs_send_fstream << "off" << std::endl;
			}
		}
	}
}

void readSettingsFile()
{
	// to do
}

void checkFirstConnection()
{

	std::ifstream read_connect_number_file_Stream("connect-number.data");
	
	int stored_connect_number = 0;
	read_connect_number_file_Stream >> stored_connect_number; // change la valeur de stored_connect_number avec le contenue du fichier

	if (read_connect_number_file_Stream)
	{
		while (true)
		{
			if (stored_connect_number == 0)
			{				
				writeSettingsConfigFirstConnect();
				//firstConnectProcess();
				break;
			}
			/*else
			{
				start();
				break;
			}*/
	
			if (stored_connect_number != 1 || 0)
			{
				std::cout << "Le contenue du fichier du nombre de connection est incorecte..." << std::endl;
				Sleep(1000);
				continue;
			}
		}
	}
	else
	{
		std::cout << "Inpossible d'ouvrir le fichier" << std::endl;
	}
}

void firstConnectProcess()
{
	writeSettingsConfigFirstConnect(); // regarder juste en dessous la fonction du processus de la première connection pour savoir ce que fais cette fonction
	start();
}

void writeSettingsConfigFirstConnect() // fonction de paramètrage lors de la première connection
{
	std::cout << "test" << std::endl;
}