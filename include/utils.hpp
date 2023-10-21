#ifndef UTILS_HPP
#define UTILS_HPP
#include <map>
#include "types.hpp"

void clean();
void paused();
void print_tag(std::string);
int print_menu(std::string);
void print_product(std::map<std::string, float>);
void print_product(std::string, std::map<std::string, float>);
std::map<std::string, float> pull_db(std::string);
void push_db(std::string, std::map<std::string, float>);
PRODUCT find_product(std::string, std::map<std::string, float>);
#endif