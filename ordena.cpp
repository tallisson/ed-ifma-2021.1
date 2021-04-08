#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
 * Função toString: retorna uma string com todos os elementos 
 * cadastrados no vetor
 * @param vetor[]: vetor de números inteiros
 * @param tamVetor: indica a quantidade de elementos no vetor
 * 
 * @return ss.str(): string com os elementos cadastrados no vetor
 */
string toString(int vetor[], int tamVetor) {
 if(tamVetor == 0) {
   return "[]";
 }
 
 stringstream ss;
 ss << "[" << vetor[0];
 for(int i = 1; i < tamVetor; i++) {
   ss << ", " << vetor[i];
 }
 ss << "]";

 return ss.str();
}

/*
 * Função bubbleSort: ordena de forma crescente um vetor
 * @param vetor[]: vetor de número inteiros a ser ordenado
 * @param tam: tamanho do vetor
 * 
 * @return void
 */
void bubbleSort(int vetor[], int tamVetor) {
  // [5, 3, 2, 1, 4, 0]
  // Flag que controla se vai ou não acontecer troca de valores
  bool fazerTroca = true;

  // Executar ordenação
  while(fazerTroca == true) {
    fazerTroca = false;
    // Iterar sobre o vetor
    for(int i = 0; i < tamVetor; i++) {     
      if(i == tamVetor - 1) {
        continue;
      }
      // Testa se valor na célula (i) é maior que o da célula (i+1)
      if(vetor[i] > vetor[i + 1]) {
        // Fazer a troca
        int aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;

        fazerTroca = true;
      }
    }
  }
}

int main(int argc, char ** argv) {
  // Criar vetor de teste
  int vetor[] = {5, 3, 2, 1, 4, 0, -1, 12, 6};
  cout << "Vetor desordenado = " << toString(vetor, 9) << endl;

  bubbleSort(vetor, 9);
  cout << "Vetor ordenado = " << toString(vetor, 9) << endl;

  return 0;
}