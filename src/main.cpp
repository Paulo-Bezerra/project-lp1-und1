#include <iostream>
#include <map>
#include "../include/client.hpp"
#include "../include/utils.hpp"
#include "../include/manager.hpp"
#include "../include/types.hpp"

using namespace std;

int main(void) {
    // declando a struct de dados do programa
    DATABASE db;
    // iniciandos os maps com os dados dos arquivos
    db.sandwiches = pull_db("sandwiches");
    db.juices = pull_db("juices");
    
    // estrutura de repetição para funcionamento durante o usuário desejar
    int op;
    while (true) {
        // imprimindo o menu principal
        clean();
        print_tag("bar-main");
        cin >> op;
        // tratando a escolha do usuário
        // menu cliente
        if (op == 1) { run_client(db); }
        // menu gerente
        else if (op == 2) { run_maneger(&db); }
        // saída do programa
        else if (op == 3) { break; }
        // tratamento de intrada inválida
        else { 
            print_tag("label-error");
            paused();
         }
    }

    clean();
    print_tag("label-shutdown");

    // salvando as modificações nos arquivos de dados
    push_db("sandwiches", db.sandwiches);
    push_db("juices", db.juices);

    cout << endl;
    return 0;
}
