#include "utilities.h"

#include <fstream>
#include <string>

void help_command(std::string file_path) 
{
	std::ifstream file(file_path);
	std::string stored_help_file_content;

	if (file.is_open())
	{
		while (std::getline(file, stored_help_file_content))
		{
			std::cout << stored_help_file_content << std::endl;

		}
		file.close();
	}

	std::cout << std::endl;
}

void write_logs(std::string logs_to_write)
{
	std::ifstream Read_logs_files("logs.txt");

	std::string stored_logs_file_Content;
	std::getline(Read_logs_files, stored_logs_file_Content);

	std::ofstream Write_logs_files("logs.txt");

	Write_logs_files << stored_logs_file_Content << "\n" << logs_to_write << std::endl;
}

void read_logs()
{
	std::ifstream Read_logs_file("logs.txt");
	std::string stored_file_content;
	
	while (std::getline(Read_logs_file, stored_file_content))
	{
		std::cout << stored_file_content << std::endl;
	}
	Read_logs_file.close();
}

// couleur pour la fonction text
#define RED "\x1B[31m"
#define GRE "\x1B[32m"
#define WHI "\033[0m\t\t"

std::string text(std::string text_to_show, std::string text_color, std::string action)
{
	if (text_color == "white" && action == "jump-line") // saute une ligne
	{
		std::cout << text_to_show << WHI << std::endl;
	}
	else if (text_color == "white" && action == "stay") // ne saute pas de ligne
	{
		std::cout << text_to_show << WHI;
	}


	if (text_color == "red" && action == "jump-line")
	{
		std::cout << RED << text_to_show << WHI << std::endl;
	}
	else if (text_color == "red" && action == "stay")
	{
		std::cout << RED << text_to_show << WHI;
	}


	if (text_color == "green" && action == "jump-line")
	{
		std::cout << GRE << text_to_show << WHI << std::endl;
	}
	else if (text_color == "green" && action == "stay")
	{
		std::cout << GRE << text_to_show << WHI;

	}

	if (action == "")
	{
		system("cls");
		std::cout << "ERREUR : action param text funtion is NULL = error(invalide-content)" << std::endl;
	}

	return "";
}
