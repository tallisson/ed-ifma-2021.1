#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef struct No {
  No * proximo;
  int valor;
  
  No() {
    proximo = NULL;
    valor = 0;
  }
  
  No(int v) {
    proximo = NULL;
    valor = v;
  }
  
  virtual ~No() {
    delete proximo;
    proximo = NULL;
  }
} No;

typedef struct ListaCircular {
  No * cursor;
  int qtdNos;
  
  ListaCircular() {
    cursor = NULL;
    
    qtdNos = 0;
  }
  
  virtual ~ListaCircular() {
    //delete cursor;
  }
  
  void avancar() {
    cursor = cursor->proximo;
  }
  
  void adicionar(int v) {
    No * novoNo = new No(v);
    
    if(qtdNos == 0)  {
      novoNo->proximo = novoNo;
      cursor = novoNo;
    } else {
      novoNo->proximo = cursor->proximo;
      cursor->proximo = novoNo;
    }
    
    qtdNos++;
  }
  
  void remover() {
    if(qtdNos == 0) {
      return;
    }
    
    if(qtdNos == 1) {
      cursor = NULL;    
    } else {
      No * aux = cursor->proximo;
      cursor->proximo = aux->proximo;
    }
    
    qtdNos--;
  }
  
  bool existe(int v) {
    No * aux = cursor;
    for(avancar(); aux != cursor; avancar()) {
      if(cursor->valor == v) {
        return true;
      }
    }  
    
    return false;
  }
  
  string toString() {
    if(qtdNos == 0) {
      return "{ }";
    }
    
    stringstream ss;
    ss << "{" << cursor->valor;
    No * aux = cursor;
    for(avancar(); aux != cursor; avancar()) {
      ss << ", " << cursor->valor;
    }
    ss << "}";
    
    return ss.str();
  }
} ListaCircular;

int main()
{
  ListaCircular l;
  
  cout << "Adicionando 1, 2 e 4" << endl;
  l.adicionar(1);
  l.adicionar(2);
  l.adicionar(4);
  cout << l.toString() << endl;
  
  cout << "Removendo 4" << endl;
  l.remover();
  cout << l.toString() << endl;
  
  cout << "Testando o existe(2)" << endl;
  if(l.existe(2) == true) {
    cout << "2 cadastrado na lista" << endl;
  }
  
  return 0;
}

