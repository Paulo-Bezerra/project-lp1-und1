#include <iostream>
#include <fstream>
#include <termios.h>
#include <unistd.h>
#include "../include/utils.hpp"
#include "../include/types.hpp"

using namespace std;

bool login() {
  string word, passwd;
  cout << "Informe a senha de acesso: ";
  // parte que eu peguei da internet para esconder a senha
  termios oldt;
  tcgetattr(STDIN_FILENO, &oldt);
  termios newt = oldt;
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); // esconde
  //**********************************************************
  cin >> word;
  // voltando ao normal
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // retorna à exibir
  //**********************************************************
  // acessando o arquivo que contém a senha
  cout << endl;

  fstream passwd_db;
  passwd_db.open("db/password", ios::in);

  // autenticando a senha
  passwd_db >> passwd;
  if (passwd != word)
    return false;
  return true;
}

// a função execulta operação de cadastro de sanduíches
void register_sandwich(map<string, float>* mapsandwiches) {
  int op;
  string buffer;
  PRODUCT sandwich;
  while (true) {
    clean();
    print_tag("form-register-sandwich");
    cin >> op;
    // verificando a opção selecionada pelo usuário
    if (op == 1) {
      // opção de cadastrar um sanduíche no arquivo de dados
      cout << "Informe o nome do sanduíche: ";
      cin >> buffer;
      // verificando se o sanduíche já foi cadastrado
      sandwich = find_product(buffer, *mapsandwiches);
      if (sandwich.name == "") {
        sandwich.name = buffer;
        cout << "Informe o preco do sanduíche: ";
        cin >> sandwich.price;
        // adicionando o sanduíche ao map
        (*mapsandwiches)[sandwich.name] = sandwich.price;
        print_tag("label-added");
        paused();
      } else {
        // caso o sanduíche já tenha sido cadastrado
        print_tag("label-sandwich-exist");
        paused();
      }
    } else if (op == 2) {
      // opção para sair do formulário de cadastro de sanduíches
      print_tag("label-canceled");
      paused();
      break;
    } else {
      // tratamento de entrada inválida
      print_tag("label-error");
      paused();
    }
  }
}

// a função execulta operação de cadastro de sucos
void register_juice(map<string, float>* mapJuices) {
  int op;
  string buffer;
  PRODUCT juice;
  while (true) {
    clean();
    print_tag("form-register-juice");
    cin >> op;
    // verificando a opção selecionada pelo usuário
    if (op == 1) {
      // opção de cadastrar um suco no arquivo de dados
      cout << "Informe o nome do suco: ";
      cin >> buffer;
      // verificando se o suco já foi cadastrado
      juice = find_product(buffer, *mapJuices);
      if (juice.name == "") {
        juice.name = buffer;
        cout << "Informe o preco do suco: ";
        cin >> juice.price;
        // adicionando o suco ao map
        (*mapJuices)[juice.name] = juice.price;
        print_tag("label-added");
        paused();
      } else {
        // caso o suco já tenha sido cadastrado
        print_tag("label-juice-exist");
        paused();
      }
    } else if (op == 2) {
      // opção para sair do formulário de cadastro de suco
      print_tag("label-canceled");
      paused();
      break;
    } else {
      // tratamento de entrada inválida
      print_tag("label-error");
      paused();
    }
  }
}

// função para alterar os preço do sanduíche
void alter_sandwich(map<string, float>* mapsandwiches) {
  int op;
  string buffer;
  PRODUCT sandwich;
  while (true) {
    clean();
    print_tag("form-alter-sandwich");
    cin >> op;
    // verificando a opção selecionada pelo usuário
    if (op == 1) {
      // opção de alterar um sanduíche no arquivo de dados
      cout << "Informe o nome do sanduíche: ";
      cin >> buffer;
      // verificando se o sanduíche já foi cadastrado
      sandwich = find_product(buffer, *mapsandwiches);
      if (sandwich.name != "") {
        cout << "Informe o preco do sanduíche: ";
        cin >> sandwich.price;
        // alterando o sanduíche no map
        (*mapsandwiches)[sandwich.name] = sandwich.price;
        print_tag("label-alter");
        paused();
      } else {
        // caso o sanduíche não tenha sido cadastrado
        print_tag("label-sandwich-not-exist");
        paused();
      }
    } else if (op == 2) {
      // opção para sair do formulário de alterar preços de sanduíches
      print_tag("label-canceled");
      paused();
      break;
    } else {
      // tratamento de entrada inválida
      print_tag("label-error");
      paused();
    }
  }
}

// função para alterar os preço do suco
void alter_juice(map<string, float>* mapJuices) {
  int op;
  string buffer;
  PRODUCT juice;
  while (true) {
    clean();
    print_tag("form-alter-juice");
    cin >> op;
    // verificando a opção selecionada pelo usuário
    if (op == 1) {
      // opção de alterar um suco no arquivo de dados
      cout << "Informe o nome do suco: ";
      cin >> buffer;
      // verificando se o suco já foi cadastrado
      juice = find_product(buffer, *mapJuices);
      if (juice.name != "") {
        cout << "Informe o preco do suco: ";
        cin >> juice.price;
        // alterando o suco no map
        (*mapJuices)[juice.name] = juice.price;
        print_tag("label-alter");
        paused();
      } else {
        // caso o suco não tenha sido cadastrado
        print_tag("label-juice-not-exist");
        paused();
      }
    } else if (op == 2) {
      // opção para sair do formulário de alterar preços de sucos
      print_tag("label-canceled");
      paused();
      break;
    } else {
      // tratamento de entrada inválida
      print_tag("label-error");
      paused();
    }
  }
}

// função para excluir o sanduíche do arquivo de dados
void delete_sandwich(map<string, float>* mapsandwich) {
  int op;
  string buffer;
  PRODUCT sandwich;
  while (true) {
    clean();
    op = print_menu("form-delete");
    if (op == 1) {
      // pede o nome do sanduíche que deseja excluir
      cout << "Informe o nome do sanduíche a ser excluído: ";
      cin >> buffer;
      // verifica se o sanduíche está presente no map
      if (find_product(buffer, *mapsandwich).name != "") {
        // deleta o sanduíche do map
        (*mapsandwich).erase(buffer);
        print_tag("label-deleted");
        paused();
      } else {
        // tramento para o caso do sanduíche não constar no map
        print_tag("label-sandwich-not-exist");
        paused();
      }
    } else if (op == 2) {
      // caso o gerente queira abortar a exclusão do sanduíche
      print_tag("label-canceled");
      paused();
      break;
    } else {
      // tratamento de entrada inválida
      print_tag("label-error");
      paused();
    }
  }
}

// função para excluir o suco do arquivo de dados
void delete_juice(map<string, float>* mapJuices) {
  int op;
  string buffer;
  PRODUCT juice;
  while (true) {
    clean();
    op = print_menu("form-delete");
    if (op == 1) {
      // pede o nome do suco que deseja excluir
      cout << "Informe o nome do suco a ser excluído: ";
      cin >> buffer;
      // verifica se o suco está presente no map
      if (find_product(buffer, *mapJuices).name != "") {
        // deleta o suco do map
        (*mapJuices).erase(buffer);
        print_tag("label-deleted");
        paused();
      } else {
        // tramento para o caso de o suco não constar no map
        print_tag("label-juice-not-exist");
        paused();
      }
    } else if (op == 2) {
      // caso o gerente queira abortar a exclusão do suco
      print_tag("label-canceled");
      paused();
      break;
    } else {
      // tratamento de entrada inválida
      print_tag("label-error");
      paused();
    }
  }
}

// a função estrutura e execulta as opções do menu gerente
void run_maneger(DATABASE* db) {
  // verificando se o usuário tem permissão de acesso
  if (!login()) {
    print_tag("incorrect-password");
    paused();
    return;
  }

  string buffer;
  PRODUCT product;
  int op;

  while (true) {
    clean();
    op = print_menu("maneger-main");
    if (op == 1) {
      // exibe os sanduíches cadastrados
      clean();
      print_product("label-sandwiches", db->sandwiches);
      paused();
    } else if (op == 2) {
      // exibe os sucos cadastados
      clean();
      print_product("label-juices", db->juices);
      paused();
    } else if (op == 3) {
      // cadastra sanduíches
      register_sandwich(&db->sandwiches);
    } else if (op == 4) {
      // cadastra sucos
      register_juice(&db->juices);
    } else if (op == 5) {
      // altera o preço de sanduíches
      alter_sandwich(&db->sandwiches);
    } else if (op == 6) {
      // altera o preço de sucos
      alter_juice(&db->juices);
    } else if (op == 7) {
      // deleta sanduíches
      delete_sandwich(&db->sandwiches);
    } else if (op == 8) {
      // deleta sucos
      delete_sandwich(&db->juices);
    } else if (op == 9) {
      // caso o gerente queira sair do menu administrador
      break;
    } else {
      // tratamento de entrada inválida
      print_tag("label-error");
      paused();
    }
  }
}