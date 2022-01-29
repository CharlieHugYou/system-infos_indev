#include "settings.h"

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

void load()
{
	/*
		Vérification des fichiers de sauvegarde 
		Si il en manque un seul le programme le signale, affiche tout les fichiers qui sont censé être présent
		Puis l'utilisateur.ice.x doit ajouter le/les fichier.s manquant
	*/

	// création des streams des fichiers

	// .set files
	std::ifstream checkLogs_set_file("logs.set");
	std::ifstream checkLogs_send_set_file("logs-notif.send.set");

	// .data files
	std::ifstream checkUser_data_file("user.data");
	std::ifstream checkConnect_number_file("connect-number.data");

	// show files
	std::ifstream checkHelp_data_show("help.data.show");

	/*std::string file_array[5] = {"logs.set", "logs-notif.send.set", "user.data", "connect-number.data", "help.data.show"};

	std::ifstream program_files(file_array[5]);*/

	std::string userInput;
	for (int i = 0; i <= 100; i++)
	{
		std::cout << "Chargement des fichiers de sauvegarde : " << i << "%" << " restant" << std::endl;
		Sleep(100);
		system("cls");

		if (i == 10)
		{
			while (i == 10)
			{
				Sleep(200);
				i++;
				std::cout << "Chargement des fichiers d'utilisateur : " << i << "%" << " restant" << std::endl;
				
				// ajouter les verif de fichier au fil de dev !
				if (!checkUser_data_file || !checkLogs_set_file || !checkLogs_send_set_file || !checkConnect_number_file || !checkHelp_data_show)
				{
					std::cout << "Un fichier est manquant dans le dossier du programme, verifier les fichiers dont le logiciel a besoin pour fonctionner avec la commande : file -list" << std::endl;

					std::getline(std::cin, userInput);

					if (userInput == "file -list" || "file --list")
					{
						std::cout << "user.data" << std::endl;
						std::cout << "logs.set" << std::endl;
						std::cout << "logs-notif.send.set" << std::endl;
						std::cout << "connect-number.data" << std::endl;
						std::cout << "help.data.show" << std::endl;

						std::cin.ignore();

						// ajouter les fichiers au fur a mesure
					}

				}
				else
				{
					continue;
				}

				if (i == 20)
				{
					system("cls");
					break;
				}
			}
		}
	}
}
