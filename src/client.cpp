#include <iostream>
#include <fstream>
#include "../include/utils.hpp"
#include "../include/types.hpp"
#include <map>

using namespace std;

/*  declaração do carrinho num escopo global
 *  para não perder as informações
 *  quando sair do menu cliente
 */
map<string, float> cart;

/*  a função pecorre o map
 *  por meio de um iterator
 *  e soma os valores dos itens
 */
float sum_cart() {
    float sum = 0;
    map<string, float>::iterator it;
    for (it = cart.begin(); it != cart.end(); it++) {
        sum += it->second;
    }
    return sum;
}

// a função execulta operação de escolher lanche
void select_item(DATABASE db) {
    int op;
    string buffer;
    PRODUCT selected;
    while (true)
    {
        clean();
        print_tag("menu-order");
        cin >> op;
        // verificando a opção selecionada pelo usuário
        if (op == 1) {
            // opção de selecionar um sanduíche para o carrinho
            clean();
            print_tag("form-order-sandwich");
            cout << "Informe o nome do sanduíche: ";
            cin >> buffer;
            // verificando se o item selecionado consta no map
            selected = find_product(buffer, db.sandwiches);
        } else if (op == 2) {
            // opção de selecionar um suco para o carrinho
            clean();
            print_tag("form-order-juice");
            cout << "Informe o nome do suco: ";
            cin >> buffer;
            // verificando se o item selecionado consta no map
            selected = find_product(buffer, db.juices);
        } else if (op == 3) {
            // opção para sair do menu de seleção para o carrinho
            print_tag("label-canceled");
            paused();
            break;
        }  
        // verificando se a busca retornou um item válido
        if (selected.name != "")
        {
            // adicionando o item ao carrinho
            cart[selected.name] = selected.price;
            print_tag("label-added");
            paused();
        }
        else {
            // tratamento de entrada inválida
            print_tag("label-error");
            paused();
        }
    }
}

// função para excluir o item do carrinho
void delete_item() {
    int op;
    string buffer;
    PRODUCT selected;
    while (true) {
        clean();
        op = print_menu("form-delete");
        if (op == 1) {
            // pede o nome do item que deseja excluir
            cout << "Informe o nome do item a ser excluído do carrinho: ";
            cin >> buffer;
            // verifica se o item está presente no carrinho
            if (find_product(buffer, cart).name != "") {
                // deleta o item do carrinho
                cart.erase(buffer);
                print_tag("label-deleted");
                paused();
            } else {
                // tramento para o caso do item não constar no carrinho
                print_tag("label-error");
                paused();
            }
        } else if (op == 2) {
            // caso o usuário queira abortar a exclusão
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

// a função estrutura e execulta as opções do menu cliente
void run_client(DATABASE db)
{
    int op;
    while (true)
    {
        clean();
        op = print_menu("client-main");
        if (op == 1)
        {
            // exibe os sanduíches cadastrados
            clean();
            print_product("label-sandwiches", db.sandwiches);
            paused();
        }
        else if (op == 2)
        {
            // exibe os sucos cadastados
            clean();
            print_product("label-juices", db.juices);
            paused();
        }
        else if (op == 3)
        {
            // execulta a função para escolher o lanche
            select_item(db);
        }
        else if (op == 4){
            // chama a função para somar os itens do carrinho e exibe o resultado
            clean();
            print_tag("label-price");
            cout << endl << "Total: .....R$ " << sum_cart() << endl;
            paused();
        }
        else if (op == 5){
            // exibe os itens do carrinho
            clean();
            print_product("label-cart", cart);
            paused();
        } else if (op == 6) {
            // menu para excluir o item do carrinho
            delete_item();
        } else if (op == 7) {
            // opção para sair do menu do cliente
            break;
        }
        else {
            // tratamento de entrada inválida
            print_tag("label-error");
            paused();
        }
    }
}
