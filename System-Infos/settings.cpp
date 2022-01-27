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
				std::ofstream write_connect_number("connect-number.data");

				write_connect_number << "1";
				firstConnectProcess();

				break;
			}
			else
			{
				start();
				break;
			}
	
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
	std::ofstream write_logs_settings("logs.set");
	std::ofstream write_logs_notif_settings("logs-notif.send.set");

	std::string userInput;

	system("cls");
	std::cout << "Ceci est le parametrage du premier lancement du programme, nous allons le parametrer a tes goût" << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Veux tu que le programme ecrive des logs dans le fichier des logs [oui] [non] : ";

	if (write_logs_notif_settings && write_logs_settings)
	{
		while (true)
		{
			std::cin >> userInput;

			if (userInput == "oui")
			{
				write_logs_settings << "ON";
				std::cout << "Ecriture de logs : \x1B[32mON\033[0m\t\t\n" << std::endl;
				Sleep(100);

				system("cls");

				std::cout << "Veux tu recevoir des notifications sur ton ordinateur si il y en a besoin [oui] [non] : ";
				std::cin >> userInput;

				if (userInput == "oui")
				{
					std::cout << "Envoie de notification : \x1B[32mON\033[0m\t\t\n" << std::endl;
					write_logs_notif_settings << "ON";
					userInput = "";
					break;
				}

				if (userInput == "non")
				{
					std::cout << "Envoie de notification : \x1B[31mOFF\033[0m\t\t\n" << std::endl;
					write_logs_notif_settings << "OFF";
					userInput = "";
					break;
				}
			}

			if (userInput == "non")
			{
				std::cout << "Ecriture de logs : \x1B[31mOFF\033[0m\t\t\n" << std::endl;
				write_logs_settings << "OFF";
				userInput = "";
				break;
			}
		}
	}
	else
	{
		std::cout << "Impossible d'ouvrir les fichiers des parametres" << std::endl;
	}
}
