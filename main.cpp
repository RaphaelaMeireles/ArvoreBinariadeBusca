//Bibliotecas necessárias
#include <iostream>
#include <stdio.h>
#include "ArvoreBinariaBusca.h"
#include <queue>;

using namespace std;

//Função principal para demonstrar o uso da Árvore Binária de Busca
int main() {

    int nivel;
    int x; //Variável utilizada para receber o valor digitado do usuário e colocar na Árvore Binária de Busca
    int opcao; //variável utilizada no Menu para testar a árvore
    int modo; //variável utilizada na escolha do percurso na árvore

    ArvoreBinariaBusca_Construtor();  //para iniciar a árvore



    do {  //menu com opções para testar a implementação da árvore


        system("cls");

        cout << "Programa para uso da Arvore Binaria de Busca\n\n";
        cout << "Escolha uma das opcoes a seguir:";
        cout << "\n\n\nMenu: \n";
        cout << "\n1 - Inserir";
        cout << "\n2 - Pesquisar";
        cout << "\n3 - Numero de elementos na arvore";
        cout << "\n4 - Vazia";
        cout << "\n5 - Percurso";
        cout << "\n6 - Imprimir um nivel\n";
        cout << "\n7 - Sair\n";
        cout << "\nOpcao: ";
        cin >> opcao;

        system("cls");

        switch (opcao) {

            case 1:
                cout << "\n\nDigite o dado: ";
                setbuf(stdin, NULL);
                cin >> x;

                if (ArvoreBinariaBusca_Inserir(x))
                    cout << "Elemento inserido\n\n";
                else cout << "Erro ao inserir elemento.\n\n";

                system("pause");
                break;


            case 2:
                cout << "\nDigite o elemento para pesquisa: ";
                setbuf(stdin, NULL);
                cin >> x;

                if (ArvoreBinariaBusca_Pesquisar(x))
                    cout << "Elemento encontrado.\n\n";
                else cout << "Elemento nao encontrado.\n\n";

                system("pause");
                break;

            case 3:
                cout << "\n\nNumero de elementos na arvore: " << ArvoreBinariaBusca_Tamanho() << "\n\n";
                system("pause");
                break;

            case 4:
                if (ArvoreBinariaBusca_Vazia())
                    cout << "Arvore vazia.\n\n";
                else cout << "A arvore nao esta vazia.\n\n";

                system("pause");
                break;

            case 5:
                cout << "\n\n\nMenu: \n";
                cout << "\n1 - Pre-ordem";
                cout << "\n2 - Em-ordem";
                cout << "\n3 - Pos-ordem\n";
                cout << "\nOpcao: ";
                cin >> modo;
                ArvoreBinariaBusca_Percurso(modo);
                break;

            case 6:
                cout << "\nDigite o nivel desejado: ";
                cin >> nivel;
                ArvoreBinariaBusca_Imprimir_Por_Nivel(nivel);
            system("pause");
            break;

            case 7:
                ArvoreBinariaBusca_Destrutor();
                break;

            default:
                cout << "\n\nOpcao invalida\n\n";
                system("pause");
        }
    } while (opcao != 7);


    return 0;
}
