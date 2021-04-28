#include <iostream>

using namespace std;

void troca(int v[], int i, int j) {
  int aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

int particionamento(int v[], int esq, int dir) {
  int pivot = v[esq];
  int i = esq;

  for(int j = esq + 1; j <= dir; j++) {
    if(v[j] <= pivot) {
      i++;
      troca(v, i, j);
    }
  }

  troca(v, esq, i);
  return i;
}

int main(int argc, char ** argv) {

  return 0;
}