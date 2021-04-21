#include <exception>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
struct No {
  No<T> * proximo;
  T valor;
  
  No(T v) {
    proximo = NULL;
    valor = v;
  }
  
  virtual ~No() {
    delete proximo;
  }
};

template <typename T>
struct Pilha {
  No<T> * topo;
  int qtd;
  
  Pilha() {
    topo = NULL; 
    qtd = 0;
  }
  
  virtual ~Pilha() {
    delete topo;
  }
  
  void empilhar(T v) {
    No<T> * novoNo = new No<T>(v);
    
    if(qtd == 0) {
      topo = novoNo;
    } else {
      novoNo->proximo = topo;
      topo = novoNo;
    } 
    
    qtd++;
  }
  
  T desempilhar() {
    if(qtd == 0) {
      throw "Pilha vazia!";
    }
    
    T temp = topo->valor;
    topo = topo->proximo;  
    qtd--;

    return temp;
  }
  
  string toString() {
    if(qtd == 0) {
      return "[]";
    }
    
    stringstream ss;
    ss << "[" << topo->valor;
    for(No<T> * aux = topo->proximo; aux != NULL; aux = aux->proximo) {
      ss << ", " << aux->valor;
    }
    ss << "]";
    
    return ss.str();
  }
};

int main () {
  Pilha<int> * p = new Pilha<int>();
  
  cout << "Push " << endl;
  p->empilhar(10);
  p->empilhar(20);
  p->empilhar(30);
  cout << p->toString() << endl;
  
  /*cout << "Pop: " << p->desempilhar() << endl;
  cout << p->toString() << endl;
  
  cout << "Pop: " << p->desempilhar() << endl;
  cout << p->toString() << endl;*/
  
  delete p;
  
  return 0;
}
