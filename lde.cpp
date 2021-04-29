#include <iostream>
#include <exception>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
struct No {
  No * proximo;
  No * anterior;
  T valor;

  No(T v) {
    anterior = NULL;
    proximo = NULL;
    valor = v;
  }
  
  virtual ~No() {
    delete proximo;
  }
};

template <typename T>
struct Deque {
  No<T> * cabeca;
  No<T> * cauda;
  int qtdNos;
  
  Deque() {
    cabeca = NULL;
    cauda = NULL;
    qtdNos = 0;
  }
  
  virtual ~Deque() {
    delete cabeca;
    cabeca = NULL;
  }
  
  // Informa se a lista está vazia
  bool vazio() {
    return qtdNos == 0;
  }
  
  void adicionarComeco(int v) {
    No<T> * novoNo = new No<T>(v);
    
    if(vazio())  {
      cabeca = novoNo;
      cauda = novoNo;
    } else {
      novoNo->proximo = cabeca;
      cabeca->anterior = novoNo;
      cabeca = novoNo;
    }
    
    qtdNos++;
  }

  void adicionarFinal(int v) {
    No<T> * novoNo = new No<T>(v);
    
    if(vazio())  {
      cabeca = novoNo;
      cauda = novoNo;
    } else {
      novoNo->anterior = cauda;
      cauda->proximo = novoNo;
      cauda = novoNo;
    }
    
    qtdNos++;
  }
  
  T removerComeco() {
    if(vazio()) {
      throw "Lista Vazia!";
    }
    
    T temp = cabeca->valor;
    if(qtdNos == 1) {
      No<T> * aux = cabeca;
      cabeca = NULL;
      cauda = NULL;
      delete aux;
    } else {
      No<T> * aux = cabeca;
      cabeca = cabeca->proximo;
      cabeca->anterior = NULL;
      aux->proximo = NULL;
      delete aux;
    }
  
    qtdNos--;
    return temp;  
  }
  
  T removerFinal() {
    if(vazio()) {
      throw "Lista Vazia!";
    }
    
    T temp = cauda->valor;
    if(qtdNos == 1) {
      No<T> * aux = cabeca;
      cabeca = NULL;
      cauda = NULL;
      delete aux;
    } else {    
      No<T> * aux = cauda;
      cauda = cauda->anterior; 
      cauda->proximo = NULL;
      aux->anterior = NULL;
      delete aux;
    }
    
    qtdNos--;
    return temp;
  }
  
  T remover(int v) {
    if(vazio()) {
      throw exception("Lista Vazia!");
    }

    if(cabeca->valor == v) {
      return removerComeco();
    }
    
    if(cauda->valor == v) {
      return removerFinal();
    }
    
    for(No<T> * aux = cabeca->proximo; aux != NULL; aux = aux->proximo) { 
      if(aux->valor == v) {
        aux->anterior->proximo = aux->proximo; 
        aux->proximo->anterior = aux->anterior;
        qtdNos--;
        return aux->valor;
      }
    }
    throw "Valor não encontrado!";
  }
  
  string toString() {
    if(vazio()) {
      return "[]";
    }
    
    stringstream ss;
    ss << "[" << cabeca->valor;
    for(No<T> * aux = cabeca->proximo; aux != NULL; aux = aux->proximo) {
      ss << ", " << aux->valor;
    }
    ss << "]";
    
    return ss.str();
  }
};

int main()
{
  Deque<int> * deque = new Deque<int>();
  
  cout << "Adicionando no Começo 1, 2 e 4" << endl;
  deque->adicionarComeco(1);
  deque->adicionarComeco(2);
  deque->adicionarComeco(4);
  cout << deque->toString() << endl;
  
  cout << "Removendo do Começo: " << endl;
  cout << deque->removerComeco() << endl;
  cout << deque->toString() << endl;
  
  cout << "Adicionando no Final 5, 6 e 7" << endl;
  //deque->adicionarFinal(5);
  //deque->adicionarFinal(6);
  //deque->adicionarFinal(7);
  cout << deque->toString() << endl;
  
  cout << "Removendo do Final: " << endl;
  cout << deque->removerFinal() << endl;
  cout << deque->removerFinal() << endl;
  cout << deque->toString() << endl;
  
  delete deque;
  return 0;
}

