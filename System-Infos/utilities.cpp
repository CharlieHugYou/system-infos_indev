#include "utilities.h"

#include <fstream>

void help_command(std::string file_path) 
{
	// to code

	std::ifstream file(file_path);
	std::string stored_help_file_content;

	if (file.is_open())
	{
		while (file >> stored_help_file_content)
		{
			std::cout << stored_help_file_content << std::endl;

		}
	}
}

void write_logs(std::string logs_to_write)
{
	// to code
	std::ofstream file("logs.txt");
}

void read_logs()
{
	// to code
}

#define RED "\x1B[31m"
#define GRE "\x1B[32m"

void text(std::string text_to_show, std::string text_color, std::string action)
{
	if (text_color == "" && action == "jump-line") // saute une ligne
	{
		std::cout << text_to_show << std::endl;
	}
	else if (text_color == "" && action == "stay") // ne saute pas de ligne
	{
		std::cout << text_to_show;
	}


	if (text_color == "red" && action == "jump-line")
	{
		std::cout << RED << text_to_show << std::endl;
	}
	else if (text_color == "red" && action == "stay")
	{
		std::cout << RED << text_to_show;
	}


	if (text_color == "green" && action == "jump-line")
	{
		std::cout << GRE << text_to_show << std::endl;
	}
	else if (text_color == "green" && action == "stay")
	{
		std::cout << GRE << text_to_show;

	}
}
