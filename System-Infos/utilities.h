#pragma once
#include <iostream>

void help_command(std::string file_path);

void write_logs(std::string logs_to_write);
void read_logs();

void text(std::string text_to_show, std::string text_color, std::string action);