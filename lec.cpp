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
struct ListaCircular {
  No<T> * cursor;
  int qtdNos;
  
  ListaCircular() {
    cursor = NULL;    
    qtdNos = 0;
  }
  
  virtual ~ListaCircular() {    
    cursor = NULL;
  }
  
  bool vazio() {
    return qtdNos == 0;
  }

  // Move o cursor adiante
  void avancar() {
    cursor = cursor->proximo;
  }

  string toString() {
    if(vazio()) {
      return "[]";
    }
    
    stringstream ss;
    ss << "[" << cursor->valor;
    No<T> * aux = cursor;
    for(avancar(); aux != cursor; avancar()) {
      ss << ", " << cursor->valor;
    }
    ss << "]";
    
    return ss.str();
  }
  
  // Adicionar após o curso
  void adicionar(T v) {
    No<T> * novoNo = new No<T>(v);
    
    if(vazio())  {
      novoNo->proximo = novoNo;
      cursor = novoNo;
    } else {
      novoNo->proximo = cursor->proximo;
      cursor->proximo = novoNo;
    }
    
    qtdNos++;
  }
  
  // Remover nó após o cursor
  T remover() {
    if(vazio()) {
      throw "Lista Vazia!";
    }

    T temp = cursor->proximo->valor;   
    if(qtdNos == 1) {
      cursor = NULL;    
    } else {
      No<T> * aux = cursor->proximo;
      cursor->proximo = aux->proximo;
    }
    
    qtdNos--;
    return temp;
  }
  
  bool existe(int v) {
    No<T> * aux = cursor;
    for(avancar(); aux != cursor; avancar()) {
      if(cursor->valor == v) {
        return true;
      }
    }  
    
    return false;
  }
};

int main()
{
  ListaCircular<int> * l = new ListaCircular<int>();
  
  cout << "Adicionando 1, 2 e 4" << endl;
  l->adicionar(1);
  l->adicionar(2);
  l->adicionar(4);
  cout << l->toString() << endl;
  
  cout << "Removendo " << l->remover() << endl;
  cout << l->toString() << endl;
  
  delete l;
  
  return 0;
}

