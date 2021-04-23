#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void merge(int v[], int esq, int meio, int dir, int tam) {
  int aux[tam];
  for(int i = esq; i <= dir; i++) {
    aux[i] = v[i];
  }

  int i = esq;
  int j = meio + 1;
  int k = esq;

  while(i <= meio && j <= dir) {
    if(aux[i] < aux[j]) {
      v[k] = aux[i++];
    } else {
      v[k] = aux[j++];
    }
    k++;
  }

  while(i <= meio) {
    v[k++] = aux[i++];
  }
  while(j <= dir) {
    v[k++] = aux[j++];
  }
}

void mergeSort(int v[], int esq, int dir, int tam) {
  if(esq >= dir) {
    return;
  }

  int meio = (esq + dir) / 2;
  mergeSort(v, esq, meio, (dir - esq + 1));
  mergeSort(v, meio + 1, dir, (dir - esq + 1));

  merge(v, esq, meio, dir, (dir - esq + 1));
}

string toString(int v[], int tam) {
  if(tam == 0) {
    return "[]";
  }

  stringstream ss;
  ss << "[" << v[0];
  for(int i = 1; i < tam; i++) {
    ss << ", " << v[i];
  }
 
  ss << "]";
  return ss.str();
}

int main(int argc, char ** argv) {
  int v[] = {10, 2, 23, 21, 9, 4, 8, 1, 34};
  int tam = (sizeof(v) / sizeof(v[0]));

  cout << toString(v, tam) << endl;
  
  mergeSort(v, 0, tam-1, tam);
  cout << toString(v, tam) << endl;
  
  return 0;
}