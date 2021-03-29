#include <exception>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef struct Node {
  Node * next;
  double value;
  
  Node() {
    next = NULL;
    value = 0;
  }
  
  Node(double v) {
    next = NULL;
    value = v;
  }
  
  virtual ~Node() {
    delete next;
  }
} Node;

typedef struct Stack {
  Node * top;
  int qtd;
  
  Stack() {
    top = NULL; 
    qtd = 0;
  }
  
  virtual ~Stack() {
    delete top;
  }
  
  void push(double v) {
    Node * newNode = new Node(v);
    
    if(qtd == 0) {
      top = newNode;
    } else {
      newNode->next = top;
      top = newNode;
    } 
    
    qtd++;
  }
  
  double pop() {
    if(qtd == 0) {
      throw "Pilha vazia!";
    }
    
    double v = top->value;
    
    top = top->next;
    if(qtd == 1) {
      top = NULL;
    }
    
    qtd--;
  }
  
  string toString() {
    if(qtd == 0) {
      return "{}";
    }
    
    stringstream ss;
    ss << "{" << top->value;
    for(Node * aux = top->next; aux != NULL; aux = aux->next) {
      ss << ", " << aux->value;
    }
    ss << "}";
    
    return ss.str();
  }
} Stack;

int main () {
  Stack q;
  
  cout << "Push " << endl;
  q.push(10);
  q.push(20);
  q.push(30);
  cout << q.toString() << endl;
  
  cout << "Pop: " << q.pop() << endl;
  cout << q.toString() << endl;
  
  cout << "Pop: " << q.pop() << endl;
  cout << q.toString() << endl;
  
  cout << "Pop: " << q.pop() << endl;
  cout << q.toString() << endl;
  
  try {
    cout << "Pop: " << q.pop() << endl;
  } catch(const char * msg) {
    cout << msg << endl;
  }
  
  cout << "Push " << endl;
  q.push(40);
  q.push(50);
  cout << q.toString() << endl;
  
  return 0;
}
