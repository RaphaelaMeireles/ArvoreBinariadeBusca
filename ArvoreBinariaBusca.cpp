//Bibliotecas necessárias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinariaBusca.h"

#include <queue>

using namespace std;

TipoCelula *Raiz;

int Contador;
void ArvoreBinariaBusca_Imprimir_Por_Nivel(int nivel) {

    queue <TipoCelula *> Fila;
    Fila.push(Raiz);
    int Atual = 0;//Variavel para definir nivel atual
    TipoCelula* NoAtual;

    while(!Fila.empty()){
        int tamanho = Fila.size();
        if(Atual==nivel) {
            for (int i = 0; i < tamanho; ++i){
            NoAtual = Fila.front();
            cout << NoAtual->Item << " " ;
            Fila.pop();
        }
            return;
    }

    for (int i = 0; i < tamanho; ++i) {
        NoAtual = Fila.front();
        Fila.pop();

        if(NoAtual->Dir != NULL) {
            Fila.push(NoAtual->Dir);
        }
        if(NoAtual->Esq != NULL) {
            Fila.push(NoAtual->Esq);
        }

    }
    Atual++;
    }
}

void ArvoreBinariaBusca_Construtor()
{

    Raiz = NULL;
    Contador = 0;
}

void ArvoreBinariaBusca_Destrutor(){


     ArvoreBinariaBusca_Destrutor(Raiz);
     Contador = 0;
}

void ArvoreBinariaBusca_Destrutor(TipoCelula *&Raiz){


     if(Raiz!=NULL)
     {
         ArvoreBinariaBusca_Destrutor(Raiz->Esq);
         ArvoreBinariaBusca_Destrutor(Raiz->Dir);
         delete(Raiz);
         Raiz = NULL;
     }
}

bool ArvoreBinariaBusca_Vazia()
{

   return Raiz == NULL;
}

int ArvoreBinariaBusca_Tamanho()
{

   return Contador;
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento)
{

     return ArvoreBinariaBusca_Inserir(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento, TipoCelula *&Raiz)
{

     if(Raiz == NULL)
     {
        if((Raiz = new(TipoCelula)) == NULL)
           return false;
        else
        {
            Raiz->Item = Elemento;
            Raiz->Esq = Raiz->Dir = NULL;
            Contador++;
            return true;
        }
     }
     else
     {
         if(Elemento < Raiz->Item)
           return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Item)
              return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Dir);
            else return false;
         }
     }
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento)
{

     return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento, TipoCelula *Raiz)
{

     if(Raiz == NULL) return false;
     else
     {
         if(Elemento < Raiz->Item)
           return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Item)
              return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Dir);
            else return true;
         }
     }
}

void ArvoreBinariaBusca_Percurso(int modo)
{

     switch (modo)
     {
        case 1: ArvoreBinariaBusca_PreOrdem(Raiz); break;
        case 2: ArvoreBinariaBusca_EmOrdem(Raiz); break;
        case 3: ArvoreBinariaBusca_PosOrdem(Raiz); break;
        default: cout <<"Ordem desconhecida";
     }
     cout << endl << endl;
     system("pause");
}

void ArvoreBinariaBusca_EmOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         ArvoreBinariaBusca_EmOrdem(Raiz->Esq);
         cout << Raiz->Item << " ";
         ArvoreBinariaBusca_EmOrdem(Raiz->Dir);
     }
}

void ArvoreBinariaBusca_PreOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         cout << Raiz->Item << " ";
         ArvoreBinariaBusca_PreOrdem(Raiz->Esq);
         ArvoreBinariaBusca_PreOrdem(Raiz->Dir);
     }
}

void ArvoreBinariaBusca_PosOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         ArvoreBinariaBusca_PosOrdem(Raiz->Esq);
         ArvoreBinariaBusca_PosOrdem(Raiz->Dir);
         cout << Raiz->Item << " ";
     }
}
