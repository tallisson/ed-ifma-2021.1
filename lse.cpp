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

typedef struct Lista {
  No * cabeca;
  No * cauda;
  int qtdNos;
  
  Lista() {
    cabeca = NULL;
    cauda = NULL;
    
    qtdNos = 0;
  }
  
  virtual ~Lista() {
    delete cabeca;
  }
  
  void adicionar(int v) {
    No * novoNo = new No(v);
    if(qtdNos > 0)  {
      cauda->proximo = novoNo;
      cauda = novoNo;
    } else {
      cabeca = novoNo;
      cauda = novoNo;  
    }
    
    qtdNos++;
  }
  
  void adicionarComeco(int v) {
    No * novoNo = new No(v);
    
    if(qtdNos == 0)  {
      cabeca = novoNo;
      cauda = novoNo;
    } else {
      novoNo->proximo = cabeca;
      cabeca = novoNo;
    }
    
    qtdNos++;
  }
  
  void removerComeco() {
    if(qtdNos == 0) {
      return;
    }

    if(qtdNos == 1) {
      cabeca = NULL;
      cauda = NULL;
    } else {
      cabeca = cabeca->proximo;
    }

    qtdNos--;
  }
  
  void removerUltimo() {
    if(qtdNos == 0) {
      return;
    }
    
    if(qtdNos == 1) {
      removerComeco();
      return;
    }
    
    No * aux;
    for(aux = cabeca; aux->proximo != cauda; aux = aux->proximo) { }
    cauda = aux; 
    cauda->proximo = NULL;
    
    qtdNos--;
  }
  
  void remover(int v) {
    if(qtdNos == 0) {
      return;
    }
    
    if(cabeca->valor == v) {
      removerComeco();
      return;
    }
    
    if(cauda->valor == v) {
      removerUltimo();
      return;
    }
    
    No * aux = cabeca->proximo;
    No * ant = cabeca;
    for(; aux != NULL; aux = aux->proximo) { 
      if(aux->valor == v) {
        break;
      }
    }
    ant->proximo = aux->proximo; 
    
    qtdNos--;
  }
  
  bool existe(int v) {
    for(No * aux = cabeca; aux != NULL; aux = aux->proximo) {
      if(aux->valor == v) {
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
    ss << "{" << cabeca->valor;
    for(No * aux = cabeca->proximo; aux != NULL; aux = aux->proximo) {
      ss << ", " << aux->valor;
    }
    ss << "}";
    
    return ss.str();
  }
} Lista;

int main()
{
  Lista l;
  
  l.adicionar(1);
  l.adicionar(2);
  l.adicionar(4);
  cout << l.toString() << endl;
  
  l.removerComeco();
  cout << l.toString() << endl;
  
  l.adicionar(5);
  l.adicionar(6);
  l.adicionar(7);
  cout << l.toString() << endl;
  
  l.removerUltimo();
  l.removerUltimo();
  cout << l.toString() << endl;
  
  cout << "Removendo 5" << endl;
  l.remover(5);
  cout << l.toString() << endl;
  
  l.adicionar(6);
  l.adicionar(7);
  cout << l.toString() << endl;
  
  if(l.existe(7) == true) {
    cout << "Nó encontrado" << endl;
  }
  
  l.adicionarComeco(1);
  cout << l.toString() << endl;
  
  return 0;
}

