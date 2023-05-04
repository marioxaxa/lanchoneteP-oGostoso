#include "cardapioHeader.hpp"
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Comida{
  string nome;
  float preco;
};

map<long long int, Comida> cardapio;

vector<Comida> carrinho;

void salvarCardapio() {
  fstream arquivoCriar;

  //cria o arquivo alunos.txt caso não exista
  arquivoCriar.open("cardapio.txt", ios::out | ios::app);
  arquivoCriar.close();
  
  //Abre o arquivo alunos.txt para leitura
  fstream arquivoler;
  arquivoler.open("cardapio.txt", ios::in);
  string linha;
  vector<string> textoLido;
  
  //Lê todas as linhas do arquivo e salva cada linha em um vector
  while(getline(arquivoler, linha)){
    textoLido.push_back(linha);
  }
  arquivoler.close(); //fecha o arquivo lido.
  

  //Transfere as linhas do vector para dentro do map
  for(int i = 0; i< textoLido.size(); i+=3){
    //stoll converte uma string para um inteiro longo
    long long int codigo = stoll(textoLido[i]);
    cardapio[codigo].nome = textoLido[i+1];
    cardapio[codigo].preco = stof(textoLido[i+2]);

  }
  
}

//Faz o cadastro do aluno com valores recebidos dos parametros
void adicionarAoCardapio(long long int codigo, string nome, float preco){
  fstream arquivo;
  arquivo.open("cardapio.txt", ios::out | ios::app);
  arquivo << codigo << endl;
  cardapio[codigo].nome = nome;
  arquivo << nome << endl;
  cardapio[codigo].preco = preco;
  arquivo << preco << endl;

  arquivo.close(); // Fecha o arquivo

  cout << "Aluno cadastrado!!!\n";
}

//Faz a listagem dos alunos
void exibirCardapio(){
  cout << "\n####  Cardapio de paus   ####\n\n";
  cout << "*************************\n";
  for(auto i : cardapio){
    cout << "Codigo: "<< i.first << endl;
    cout << "Comida: "<< i.second.nome << endl;
    cout << "Preço: "<< i.second.preco << endl;
    cout << "*************************\n";
}
}

//Atualiza o arquivo para excluir a linha apagada
void atualizarArquivoCardapio(){
  fstream arquivo;
  arquivo.open("cardapio.txt", ios::out); //Apaga o arquivo original
  
  //Reescreve todo o arquivo do zero com os dados do map
  for(auto i : cardapio){
    arquivo << i.first << endl;
    arquivo << i.second.nome << endl;
    arquivo << i.second.preco << endl;
  }
}


float retornarValorDaCompra() {
  float total = 0;
    for(auto i : carrinho){
      total+= i.preco;
    }
  return total;
}

void exibirCarrinho(){
  cout << "\n####    Seu cu     ####\n\n";
  cout << "*************************\n";
  if(carrinho.size() == 0){
    cout << "Seu cu está vazio ._." << endl;
    cout << "Para preenche-lo escolha uma pika" << endl;
  } else {

    /*

    for (auto i = vetor.begin(); i != vetor.end(); i++) {
      int index = i - vetor.begin();
    }
    
    */
    for (auto i = carrinho.begin(); i != carrinho.end(); i++) {
      int index = i - carrinho.begin();
      cout << index + 1 << " - " << i->nome << "-----" << i->preco <<  endl;
    }
      cout << "Total -----" << retornarValorDaCompra() << endl;
  }
  cout << "*************************\n";
}

void adicionarAoCarrinho(long long int codigo){
  
  for(auto i : cardapio){
    if(i.first == codigo){
      carrinho.push_back(i.second);
      cout << "Comida adicionada ao carrinho." << endl;
    }   
  }
}


void excluirDoCarrinho(long long int codigo){
    if(!carrinho.empty()){
      carrinho.erase(carrinho.begin()+codigo - 1);
      atualizarArquivoCardapio(); // Chama a função para atualizar o arquivo
      cout << "Item excluido com sucesso" << endl;
      return;
    }   
  cout << "Item não encontrado!!!" << endl;
  return;
}

void cancelarCompra(){
  carrinho.clear();
}

void adicionarAoCardapio(string nome, float preco){
  cardapio.end()->second.nome = nome;
  cardapio.end()->second.preco = preco;
}

void excluirDoCardapio(long long int codigo){
    if(!cardapio.empty()){
      cardapio.erase(codigo);
      atualizarArquivoCardapio(); // Chama a função para atualizar o arquivo
      cout << "Item excluido com sucesso" << endl;
      return;
    }   
  cout << "Item não encontrado!!!" << endl;
  return;
}

void alterarPreco(long long int codigo, float preco){
  cardapio[codigo].preco = preco; 
  atualizarArquivoCardapio();
  return;
}


