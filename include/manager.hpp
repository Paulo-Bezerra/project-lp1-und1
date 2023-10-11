#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "types.hpp"

bool login();
void register_sandwich(std::map<std::string, float>*);
void register_juice(std::map<std::string, float>*);
void alter_sandwich(std::map<std::string, float>*);
void alter_juice(std::map<std::string, float>*);
void delete_sandwich(std::map<std::string, float>*);
void delete_juice(std::map<std::string, float>*);
void run_maneger(DATABASE*);
#endif