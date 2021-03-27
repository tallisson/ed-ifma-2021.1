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

typedef struct Queue {
  Node * front;
  Node * tail;
  int qtd;
  
  Queue() {
    front = NULL;  
    tail = NULL;
    qtd = 0;
  }
  
  virtual ~Queue() {
    delete front;
  }
  
  void enqueue(double v) {
    Node * newNode = new Node(v);
    
    if(qtd == 0) {
      front = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    } 
    
    qtd++;
  }
  
  double dequeue() {
    if(qtd == 0) {
      throw "Fila vazia!";
    }
    
    double v = front->value;
    
    front = front->next;
    if(qtd == 1) {
      tail = NULL;
    }
    
    qtd--;
  }
  
  string toString() {
    if(qtd == 0) {
      return "{}";
    }
    
    stringstream ss;
    ss << "{" << front->value;
    for(Node * aux = front->next; aux != NULL; aux = aux->next) {
      ss << ", " << aux->value;
    }
    ss << "}";
    
    return ss.str();
  }
} Queue;

int main () {
  Queue q;
  
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  cout << q.toString() << endl;
  
  cout << "Desenfileirando: " << q.dequeue() << endl;
  cout << q.toString() << endl;
  
  cout << "Desenfileirando: " << q.dequeue() << endl;
  cout << q.toString() << endl;
  
  cout << "Desenfileirando: " << q.dequeue() << endl;
  cout << q.toString() << endl;
  
  try {
    cout << "Desenfileirando: " << q.dequeue() << endl;
  } catch(const char * msg) {
    cout << msg << endl;
  }
  
  q.enqueue(40);
  q.enqueue(50);
  cout << q.toString() << endl;
  
  return 0;
}
