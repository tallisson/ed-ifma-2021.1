#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include "aspecto.h"

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
struct Fila {
  No<T> * frente;
  No<T> * cauda;
  int qtd;
  
  Fila() {
    frente = NULL;  
    cauda = NULL;
    qtd = 0;
  }
  
  virtual ~Fila() {
    delete frente;
  }
  
  void enfileirar(T v) {
    No<T> * novoNo = new No<T>(v);
    
    if(qtd == 0) {
      frente = novoNo;
      cauda = novoNo;
    } else {
      cauda->proximo = novoNo;
      cauda = novoNo;
    } 
    
    qtd++;
  }
  
  T desenfileirar() {
    if(qtd == 0) {
      throw "Fila vazia!";
    }
    
    T v = frente->valor;
    
    if(qtd == 1) {
      frente = NULL;
      cauda = NULL;
    } else {
      frente = frente->proximo;
    }
    
    qtd--;
    return v;
  }
  
  string toString() {
    if(qtd == 0) {
      return "[]";
    }
    
    stringstream ss;
    ss << "[" << frente->valor;
    for(No<T> * aux = frente->proximo; aux != NULL; aux = aux->proximo) {
      ss << ", " << aux->valor;
    }
    ss << "]";
    
    return ss.str();
  }
};

int main () {
  Fila<int> * q = new Fila<int>();
  
  q->enfileirar(10);
  q->enfileirar(20);
  q->enfileirar(30);
  cout << q->toString() << endl;
  
  cout << "Desenfileirando: " << q->desenfileirar() << endl;
  cout << q->toString() << endl;
  
  cout << "Desenfileirando: " << q->desenfileirar() << endl;
  cout << q->toString() << endl;
  
  cout << "Desenfileirando: " << q->desenfileirar() << endl;
  cout << q->toString() << endl;
  
  cout << "Soma = " << soma(10.1, 1.0) << endl;

  delete q;
  return 0;
}
