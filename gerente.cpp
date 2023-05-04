#include "mainHeader.hpp"
#include <stdlib.h>
#include "cardapioHeader.hpp"
#include <fstream>
#include <string>
using namespace std;

void gerente() {
  cin.ignore();
  salvarCardapio();
  

  while(true){
    exibirCardapio();
    cout << "Adicionar ao cardapio  - A" << endl;
    cout << "Excluir do cardapio    - E" << endl;
    cout << "Alterar preço          - P" << endl;
    cout << "Voltar a tela anterior - V" << endl;
    string codigo;
    cin >> codigo;
    if(codigo == "A"){
      string nome;
      float preco;
      cout << "Digite o nome do prato: " << endl;
      getline(cin, nome);
      cout << "Digite o preço do prato: " << endl;
      cin >> preco;

      adicionarAoCardapio(nome, preco);
      
    } else if (codigo == "E") {
      cout << "Informe o numero do item a ser excluido." << endl;
      cin >> codigo;
      long long int codLL = stoll(codigo);
      excluirDoCardapio(codLL);
    } else if (codigo == "P") {

    } else if (codigo == "V") {
      break;
    } 
  }
  
  return;
}