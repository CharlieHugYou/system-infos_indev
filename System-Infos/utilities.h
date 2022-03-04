#pragma once
#include <iostream>

void display_file_content_command(std::string file_path);

void write_logs(std::string logs_to_write);
void read_logs();

std::string text(std::string text_to_show, std::string text_color, std::string action);