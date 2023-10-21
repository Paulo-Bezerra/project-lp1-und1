#include <iostream>
#include <fstream>
#include <map>
#include "../include/types.hpp"
using namespace std;

// limpar a tela
void clean() {
  system("clear");
}

// serve para pausar o programa, por exemplo antes de limpar a tela
void paused() {
  cout << endl << "Tecle enter para continuar...";
  getchar();
  getchar();
}

// Importa textos selecionados por meio das tags...
void print_tag(string tag) {
  // abrindo o arquivo em modo de leitura com os textos e ajustando as strings para comparação
  fstream menus_db;
  string path = "db/texts", buffer, init = "", end = "";
  menus_db.open(path, ios::in);
  init.append("<").append(tag).append(">");
  end.append("</").append(tag).append(">");

  // indo até a posição do texto referente a tag
  while (getline(menus_db, buffer)) {
    if (buffer == init) break;
  }

  // imprimindo o conteúdo da tag
  while (getline(menus_db, buffer)) {
    if (buffer == end) break;
    cout << buffer << endl;
  }
  // fechando o acesso ao arquivo
  menus_db.close();
}

// imprime um menu e retorna a escolha do usuário
int print_menu(string tag) {
  int op;
  print_tag(tag);
  cin >> op;
  return op;
}

// imprime os produtos de um map
void print_product(map<string, float> db) {
  // iterator necessario para pecorrer o map
  map<string, float>::iterator it;
  // pecorrendo e imprimindo os produtos do map
  for (it = db.begin(); it != db.end(); it++) {
    cout << it->first
      << " ......: R$ "
      << it->second << endl;
  }
}

// uma variação para imprimir um texto de título
void print_product(string tag, map<string, float> db) {
  print_tag(tag);
  print_product(db);
}

// a função retorna um mapa com os valores dos arquivos de dados
map<string, float> pull_db(string name_db) {
  map<string, float> db;
  fstream archive_db;
  string path = "db/", product, price;

  // o nome passado completa o caminho para abrir o arquivo em modo de leitura
  path.append(name_db);
  archive_db.open(path, ios::in);

  // faz a leitura do arquivo e adiciona os dados no map
  while (getline(archive_db, product)) {
    getline(archive_db, price);
    db[product] = stof(price);
  }

  // fechando o arquivo
  archive_db.close();
  return db;
}

// envio dos dados para o arquivo de dados
void push_db(string name_db, map<string, float> db) {
  fstream archive_db;
  string path = "db/";

  // o nome passado completa o caminho para abrir o arquivo em modo de escrita
  path.append(name_db);
  archive_db.open(path, ios::out);
  // inserindo cada item do map em no arquivo
  map<string, float>::iterator it;
  for (it = db.begin(); it != db.end(); it++) {
    archive_db << it->first << endl
      << it->second << endl;
  }
  // fechando o arquivo
  archive_db.close();
}

// buscando um item e o retornando em forma de struct PRODUCT 
PRODUCT find_product(string name, map<string, float> db) {
  // declarando e iniciando a struct do tipo PRODUCT
  PRODUCT selected;
  selected.name = "";
  selected.price = 0.0;

  // percorrendo o map por meio de um iterator
  map<string, float>::iterator it;
  for (it = db.begin(); it != db.end(); it++) {
    if (name == it->first) {
      selected.name = it->first;
      selected.price = it->second;
      break;
    }
  }
  // retorna as informações do ítem preenchidas ou nada se não for encontrado
  return selected;
}