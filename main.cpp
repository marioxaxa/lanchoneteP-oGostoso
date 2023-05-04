#include <iostream>
#include "mainHeader.hpp"
#include "cardapioHeader.hpp"
#include "logoHeader.hpp"
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
  while (true){

    cout << "\n#############################\n";
      cout << "##  LANCHONETE PAU A GOSTO ##\n";
      cout << "##   Onde o seu prazer é   ##\n";
      cout << "##  especialidade da casa. ##\n";
      cout << "##          😈🍆           ##\n";
      cout << "#############################\n\n";

    logo(2);
    
    
    cout << "Escolha seu perfil:" << endl;
    cout << "1 - Cliente" << endl;
    cout << "2 - Gerente" << endl;
    cout << "3 - Sugerir paus" << endl;
    cout << "X - Fechar programa" << endl;
  
    char perfil;
    cin >> perfil;

    if (perfil == '1'){
      cliente();
    } else if (perfil == '2') {
      cout << "Escreva sua senha para entrar no perfil de gerencia:" << endl;
      string senha;
      cin >> senha;
      if (senha == "1234"){
        cout << "Gerente logado com sucesso"  << endl;
        gerente();
      }
    } else if (perfil == 'X') {
      break;
    }else{
      cout<<"Por favor selecione um comando valido.\n";
    }
  }
}