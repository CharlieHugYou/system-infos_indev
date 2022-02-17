#include "settings.h"
#include "Main.h"
#include "utilities.h"

#include <iostream>
#include <fstream>
#include <Windows.h>

void settingsMenu()
{
	std::string userInput;

	while (true)
	{
		system("cls");

		std::cout << "Menu des parametres" << std::endl
			<< "| -- > 1. Parametres d'affichage" << std::endl
			<< "| -- > 2. Parametres des logs" << std::endl
			<< "| -- > 3. Ouverture de certains fichiers texte" << std::endl
			<< "| -- > 4. Retourner au menu principale" << std::endl;

		std::cin >> userInput;

		if (userInput == "1")
		{
			writeSettings(1);
			continue;
		}

		if (userInput == "2")
		{
			writeSettings(2);
			continue;
		}

		if (userInput == "3")
		{
			writeSettings(3);
			continue;
		}

		if (userInput == "4")
		{
			system("cls");
			break;
		}
	}
}

void writeSettings(int goto_menu)
{
	system("cls");


	std::string userInput;
	
	if (goto_menu == 1)
	{
		while (true)
		{

			std::ifstream read_display_settings("text-display.set");

			std::string stored_display_settings_value;
			read_display_settings >> stored_display_settings_value;

			text("Menu des parametres -> affichage", "white", "jump-line");

			std::cout << "| -- > Le parametre des couleur du text est en " << stored_display_settings_value << std::endl;

			if (stored_display_settings_value == "ON")
			{
				std::cout << "Passer la veleur en OFF ? [oui] [non] : ";

				std::cin >> userInput;

				if (userInput == "oui")
				{
					std::ofstream write_display_settings("text-display.set");
					text("Passage de la valeur en OFF", "white", "jump-line");
					write_display_settings << "OFF";


					break;
				}

				if (userInput == "non")
				{
					text("Aucun changement effectuer", "white", "jump-line");

					break;
				}

			}

			if (stored_display_settings_value == "OFF")
			{
				std::cout << "Passer la veleur en ON ? [oui] [non] : ";

				std::cin >> userInput;

				if (userInput == "oui")
				{
					std::ofstream write_display_settings("text-display.set");
					text("Passage de la valeur en ON", "white", "jump-line");
					write_display_settings << "ON";

					break;
				}

				if (userInput == "non")
				{
					text("Aucun changement effectuer", "white", "jump-line");

					break;
				}

			}
		}
	}

	if (goto_menu == 2)
	{
		while (true)
		{
			std::ifstream read_los_settings("logs.set");

			std::string stored_logs_settings_value;
			read_los_settings >> stored_logs_settings_value;

			std::ifstream read_logs_notif_settings("logs-notif.send.set");

			std::string stored_logs_notif_settings_value;
			read_logs_notif_settings >> stored_logs_notif_settings_value;


			std::cout << "Menu des parametres -> logs" << std::endl
				<< "| -- > 1. Ecriture de logs" << std::endl
				<< "| -- > 2. Envoie de notification" << std::endl
				<< "| -- > 3. Retourner au menu des parametres" << std::endl;

			std::cin >> userInput;
			system("cls");

			if (userInput == "1")
			{
				std::cout << "Parametrage d'ecriture de logs" << std::endl
					<< "| -- > L'ecriture de logs est en " << stored_logs_settings_value << std::endl;

				if (stored_logs_settings_value == "ON")
				{
					std::cout << "Passer la valeur en OFF ? [oui] [non] : ";
					std::cin >> userInput;

					if (userInput == "oui")
					{
						std::ofstream write_logs_settings("logs.set");
						text("Passage de la valeur en OFF", "white", "jump-line");
						write_logs_settings << "OFF";

						Sleep(100);
						continue;
					}

					if (userInput == "non")
					{
						text("Aucun changement de valeur a etait effectuter", "white", "jump-line");
						continue;
					}
				}

				if (stored_logs_notif_settings_value == "OFF")
				{
					std::cout << "Passer la valeur en ON ? [oui] [non] : ";
					std::cin >> userInput;

					if (userInput == "oui")
					{
						std::ofstream write_logs_settings("logs-notif.send.set");
						text("Passage de la valeur en ON", "white", "jump-line");
						write_logs_settings << "ON";

						Sleep(1000);
						continue;
					}

					if (userInput == "non")
					{
						text("Aucun changement de valeur a etait effectuter", "white", "jump-line");
						continue;
					}
				}

			}

			if (userInput == "2")
			{
				std::cout << "Parametrage d'envoie de notifications" << std::endl
					<< "| -- > L'envoie de notificaiotn est en " << stored_logs_notif_settings_value << std::endl;

				if (stored_logs_notif_settings_value == "ON")
				{
					std::cout << "Passer la valeur en OFF ? [oui] [non] : ";
					std::cin >> userInput;

					if (userInput == "oui")
					{
						std::ofstream write_logs_notif_settings("logs-notif.send.set");
						text("Passage de la valeur en OFF", "white", "jump-line");
						write_logs_notif_settings << "OFF";

						Sleep(100);
						continue;
					}

					if (userInput == "non")
					{
						text("Aucun changement de valeur a etait effectuter", "white", "jump-line");
						continue;
					}
				}

				if (stored_logs_notif_settings_value == "OFF")
				{
					std::cout << "Passer la valeur en ON ? [oui] [non] : ";
					std::cin >> userInput;

					if (userInput == "oui")
					{
						std::ofstream write_logs_notif_settings("logs-notif.send.set");
						text("Passage de la valeur en ON", "white", "jump-line");
						write_logs_notif_settings << "ON";

						Sleep(1000);
						continue;
					}

					if (userInput == "non")
					{
						text("Aucun changement de valeur a etait effectuter", "white", "jump-line");
						continue;
					}
				}
			}

			if (userInput == "3")
			{
				system("cls");
				break;
			}
		}
	}

	if (goto_menu == 3)
	{
		text("Le programme peut avoir besoin d'ouvrir des fichiers pour vous facilité la lecture de ses dernier", "white", "jump-line");
		
		std::ifstream read_open_file_set("open-file.set");

		std::string open_file_set_Content;

		while (read_open_file_set >> open_file_set_Content)
		{
			if (open_file_set_Content == "ON")
			{
				std::cout << "La valeur est en ON, veux tu passer la veleur en OFF [oui] [non] : ";
				std::cin >> userInput;

				if (userInput == "oui")
				{
					std::ofstream write_open_file_set("open-file.set");

					write_open_file_set << "OFF";

					std::cout << "Passage de la veleur en OFF" << std::endl;
				}

				if (userInput == "non")
				{
					continue;
				}
			}

			if (open_file_set_Content == "OFF")
			{
				std::cout << "La valeur est en OFF, veux tu passer la veleur en ON [oui] [non] : ";
				std::cin >> userInput;

				if (userInput == "oui")
				{
					std::ofstream write_open_file_set("open-file.set");

					write_open_file_set << "ON";

					std::cout << "Passage de la valeur en ON" << std::endl;
				}

				if (userInput == "non")
				{
					continue;
				}
			}
		}
	}
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
				write_connect_number.close();
				firstConnectProcess();

				break;
			}
			else if(stored_connect_number >= 1)
			{
				read_connect_number_file_Stream.close();
				menu();
				break;
			}
			else if (stored_connect_number != 1 || 0)
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
	menu();
}

void writeSettingsConfigFirstConnect() // fonction de paramètrage lors de la première connection
{
	user user;

	std::ofstream write_logs_settings("logs.set");
	std::ofstream write_logs_notif_settings("logs-notif.send.set");

	std::ofstream write_display_settings("text-display.set");

	std::ofstream write_user_name("user.data");

	std::string userInput;

	system("cls");
	std::cout << "Ceci est le parametrage du premier lancement du programme, nous allons le parametrer a tes gout" << std::endl;
	std::cout << std::endl;

	if (write_logs_notif_settings && write_logs_settings)
	{
		while (true)
		{

			text("Maintenent tu dois parametrer les parametre d'affichage, veux tu activer la couleur dans le texte ? [oui] [non] : ", "white", "stay");

			std::cin >> userInput;
			if (userInput == "oui")
			{
				write_display_settings << "ON";
				std::cout << "Affichage du texte en couleur : " << text("ON", "green", "jump-line");
			}

			if (userInput == "non")
			{
				write_display_settings << "OFF";
				std::cout << "Affichage du texte en couleur : " << text("OFF", "white", "jump-line");
			}
			write_display_settings.close();

			std::cout << "Veux tu que le programme ecrive des logs dans le fichier des logs [oui] [non] : ";

			std::cin >> userInput;

			if (userInput == "oui")
			{
				write_logs_settings << "ON";

				std::ifstream read_text_display("text-display.set");
				std::string read_text_display_content;
				read_text_display >> read_text_display_content;
				
				if (read_text_display_content == "ON")
				{
					std::cout << "Ecriture de logs : " << text("ON", "green", "jump-line");
				}
				else if (read_text_display_content == "OFF")
				{
					std::cout << "Ecriture de logs : " << text("ON", "white", "jump-line");
				}

				text("Tu veux que le logiciel envoie des notificaition sur ton pc ? [oui] [non]", "white", "stay");
				std::cin >> userInput;

				if (userInput == "oui")
				{
					write_logs_notif_settings << "ON";

					if (read_text_display_content == "ON")
					{
						std::cout << "Envoie de notifications : " << text("ON", "green", "jump-line");
					}
					else if (read_text_display_content == "OFF")
					{
						std::cout << "Envoie de notifications : " << text("ON", "white", "jump-line");
					}

				}

				if (userInput == "non")
				{
					write_logs_notif_settings << "OFF";

					if (read_text_display_content == "ON")
					{
						std::cout << "Envoie de notifications : " << text("OFF", "red", "jump-line");
					}
					else if (read_text_display_content == "OFF")
					{
						std::cout << "Envoie de notifications : " << text("OFF", "white", "jump-line");
					}
				}
			}

			if (userInput == "non")
			{
				std::cout << "Ecriture de logs : \x1B[31mOFF\033[0m\t\t\n" << std::endl;
				write_logs_settings << "OFF";
				userInput = "";
			}

			std::cout << "veux tu que le programme ouvre des fichiers dans un application exertene a System-infos [oui] [non] : ";
			std::cin >> userInput;

			if (userInput == "oui")
			{
				if (userInput == "oui")
				{
					std::ofstream write_open_file_set("open-file.set");

					write_open_file_set << "ON";
				}

				if (userInput == "non")
				{
					std::ofstream write_open_file_set("open-file.set");

					write_open_file_set << "OFF";
				}
			}

			system("cls");

			std::cout << "Entre ton nom d'utilisateur : ";
			std::cin >> user.name;

			write_user_name << user.name << "\n" << "false";

			std::cout << "Ton nom est : " << user.name << std::endl;

			break;
		}
	}
	else
	{
		std::cout << "Impossible d'ouvrir les fichiers des parametres" << std::endl;
	}
}

// Si tu vois ça sache que tu es magnifique
