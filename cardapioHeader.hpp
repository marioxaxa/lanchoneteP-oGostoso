  #include <iostream>
#ifndef CARDAPIOHEADER_HPP
#define CARDAPIOHEADER_HPP
using namespace std;

void salvarCardapio();
void adicionarAoCardapio(long long int id, string nome, float preco);
void exibirCardapio();
void atualizarArquivoCardapio();
void adicionarAoCarrinho(long long int codigo);
void exibirCarrinho();
float retornarValorDaCompra();
void cancelarCompra();
void excluirDoCarrinho(long long int codigo);
void adicionarAoCardapio(string nome, float preco);
void excluirDoCardapio(long long int codigo);

#endif