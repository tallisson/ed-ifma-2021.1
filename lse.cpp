#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Struct Nó
typedef struct No {
  // Propriedades do No
  No * proximo;
  string valor;

  /* 
   * Construtor: são executados qnd criamos um nó
   * e um construtor reserva um pedaço de memória
   * p/ o Nó e inicializa as propriedades do Nó
   */
  No() {
    proximo = NULL;
  }
  No(string v) {
    proximo = NULL;
    valor = v;
  }

  /*
   * Destrutor do Nó: executado qnd um Nó for removido
   * da memória e limpa (desaloca) a referência proximo
   */
  virtual ~No() {
    delete proximo;
    proximo = NULL;
  }

  void print() {
    cout << "{ prox: " << proximo << ", valor: " << valor << "}\n";
  }
} No;

// Struct ListaSimples
typedef struct ListaSimples {
  // Propriedades
  No * cabeca; // 1º nó da lista
  No * cauda; // último nó da lista
  int qtdNos; // Contabiliza a qtd de nós na lista

  // Construtor
  ListaSimples() {
    cabeca = NULL;
    cauda = NULL;
    qtdNos = 0;
  }

  ~ListaSimples() {
    delete cabeca;
    cabeca = NULL;
  }

  // Funções Auxiliares
  int qtd() {
    return qtdNos;
  }

  bool vazio() {
    if(qtd() == 0) {
      return true; // Lista Vazia
    }

    return false; // Lista não vazia
  }

  string toString() {
    if(vazio() == true) {
      return "[]";
    }

    stringstream ss;
    ss << "[" << cabeca->valor;
    
    No * aux;
    for(aux = cabeca->proximo; aux != NULL; aux = aux->proximo) {
      ss << ", " << aux->valor;
    }
    ss << "]";

    return ss.str();
  }

  // Funções Principais
  // Adiciona na cabeça da lista
  void adicionarInicio(string v) {
    No * novoNo = new No(v);
    novoNo->proximo = cabeca;
    cabeca = novoNo;

    if(vazio() == true) {
      cauda = novoNo;
    }

    qtdNos++; // qtdNos = qtdNos + 1
  }

  // Adiciona na cauda da lista
  void adicionarFinal(string v) {
    No * novoNo = new No(v);

    if(vazio() == true) {           
      cabeca = novoNo;
      cauda = novoNo;
    } else {
      cauda->proximo = novoNo;
      cauda = novoNo;
    }

    qtdNos++;
  }

  // Remove a cabeça da lista
  string removerComeco() {
    if(vazio() == true) {
      cout << "Lista Vazia!" << endl;
      return "";
    }
    
    string temp = cabeca->valor;
    No * aux = cabeca;
    cabeca = cabeca->proximo;
    aux->proximo = NULL;
    delete aux;
    if(qtd() == 1) {
      cauda = NULL;
    }

    qtdNos--; // qtdNos = qtdNos - 1
    return temp;
  }

  // Remove a cauda da lista
  string removerFinal() {
    if(vazio() == true) {
      cout << "Lista Vazia!" << endl;
      return ""; // String vazia
    }

    string temp = cauda->valor;
    if(qtd() == 1) {      
      cauda = NULL;
      cabeca = NULL;
    } else {
      No * ant;
      for(ant = cabeca; ant->proximo != cauda; ant = ant->proximo); 
      No * aux = cauda;
      cauda = ant;
      cauda->proximo = NULL;
      delete aux;
    }

    qtdNos--;
    return temp;
  }
} ListaSimples;

int main(int argc, char ** argv) {
  // Testar a adição no inicio da Lista
  ListaSimples * ls = new ListaSimples();
  ls->adicionarFinal("Mariana");
  cout << ls->toString() << endl;

  ls->adicionarFinal("Perivaldo");
  cout << ls->toString() << endl;

  ls->adicionarFinal("Leane");  
  cout << ls->toString() << endl;

  ls->adicionarFinal("Fernandes");
  cout << ls->toString() << endl;

  for(int i = 0; i < 5; i++) {
    cout << "Removendo " << ls->removerComeco() << endl;
    cout << ls->toString() << endl;
  }

  delete ls;
  return 0;
}