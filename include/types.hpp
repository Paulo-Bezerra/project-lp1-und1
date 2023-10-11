#ifndef TYPES_HPP
#define TYPES_HPP
#include <map>

// estrutura com a forma dos dados de um produto
typedef struct {
    std::string name;
    float price;  
} PRODUCT;

// estrutura para guardar os dois maps juntos
typedef struct {
    std::map<std::string, float> sandwiches;
    std::map<std::string, float> juices;  
} DATABASE;
#endif

