#include <iostream>
#include <string>
#include <sstream>

#define CAPACIDADE_MAX 10

using namespace std;

typedef struct Vetor {
  double * valores;
  int qtd;
  
  Vetor() {
    valores = new double[CAPACIDADE_MAX];
    
    qtd = 0;
  }
  
  virtual ~Vetor() {
    delete[] valores;
  }
  
  void add(double v) { 
    valores[qtd++] = v;
  }
  
  string toString() {
    if(qtd == 0) {
      return "{}";
    }
    
    stringstream ss;
    ss << "{" << valores[0];
    for(int i = 1; i < qtd; i++) {
      ss << ", " << valores[i];
    }
    ss << "}";
    
    return ss.str();
  }
  
  void sortAsc() {
    int aux = 0;
    for (int k = 1; k < qtd; k++) {
      for (int j = 0; j < qtd - k; j++) {
        if (valores[j] > valores[j + 1]) {
          aux = valores[j];
          valores[j] = valores[j + 1];
          valores[j + 1] = aux;
        }
      }
    }
  }
  
  void sortDec() {
    int aux = 0;
    for (int k = 1; k < qtd; k++) {
      for (int j = 0; j < qtd - k; j++) {
        if (valores[j] < valores[j + 1]) {
          aux = valores[j];
          valores[j] = valores[j + 1];
          valores[j + 1] = aux;
        }
      }
    }
  }
  
  void sort(string mode = "asc") {
    if(mode == "asc") {
      sortAsc();
    } else if(mode == "dec") {
      sortDec();
    }
  }
  
  double binarySearch(double v) {
    int firstIndex = 0;
    int lastIndex = qtd;
    int middleIndex;
    
    while(firstIndex <= lastIndex) {
      middleIndex = (firstIndex + lastIndex) / 2;
    
      if(valores[middleIndex] < v) {
        firstIndex = middleIndex + 1;
      } else if(valores[middleIndex] > v) {
        lastIndex = middleIndex - 1;
      } else {
        return middleIndex;
      }
    }
    
    return -1;
  }
  
  double mean() {
    double m = 0;
    
    for(int i = 0; i < qtd; i++) {
      m += valores[i];
    }
    
    m = m / qtd;
    return m;
  }
} Vetor;

int main () {
  Vetor v;
  
  v.add(30);
  v.add(10);
  v.add(5);
  v.add(12);
  v.add(3);
  v.add(23);
  cout << v.toString() << endl;
  
  v.sort("dec");
  cout << "Vetor em ordem decrescente " << endl;
  cout << v.toString() << endl;
  
  v.sort();
  cout << "Vetor em ordem crescente " << endl;
  cout << v.toString() << endl;
  
  double index = v.binarySearch(23);
  if(index != -1) {
    cout << "Elemento na posicao " << index << endl;
  } else {
    cout << "Elemento não encontrado!" << endl;
  }
  
  cout << "Média = " << v.mean() << endl;
  
  return 0;
}
