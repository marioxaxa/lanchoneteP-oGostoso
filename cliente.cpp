#include "mainHeader.hpp"
#include <stdlib.h>
#include "cardapioHeader.hpp"
#include <fstream>
#include <string>
using namespace std;

void cliente() {
  cin.ignore();
  salvarCardapio();
  

  while(true){
    exibirCardapio();
    exibirCarrinho();
    cout << "Concluir compra        - C" << endl;
    cout << "Cancelar compra        - X" << endl;
    cout << "Excluir um item        - E" << endl;
    cout << "Voltar a tela anterior - V" << endl;
    cout << "Adicione um produto escrevendo o codigo" << endl;
    string codigo;
    cin >> codigo;
    if(codigo == "C"){
      exibirCarrinho();
      cout << "Total a ser pago: " << retornarValorDaCompra() << endl;
    } else if (codigo == "X") {
      cancelarCompra();
    } else if (codigo == "E") {
      cout << "Informe o numero do item a ser excluido." << endl;
      cin >> codigo;
      long long int codLL = stoll(codigo);
      excluirDoCarrinho(codLL);
    } else if (codigo == "V") {
      break;
    } else {
      long long int codLL = stoll(codigo);
      adicionarAoCarrinho(codLL);
    }
    
  }
  
  return;
}