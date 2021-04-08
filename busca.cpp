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
 * Função buscaSeq: pesquisa, de forma sequencial,
 * se um determinado valor está cadastrado no vetor de entrada
 * @param vetor[]: vetor de números inteiros
 * @param tamVetor: indica a qtd de elementos registrados no vetor
 * @param pesquisado: valor a ser pesquisado no vetor
 * 
 * @return true: caso o valor pesquisado seja encontrado
 * @return false: se o valor não for encontrado
 */
bool buscSeq(int vetor[], int tamVetor, int pesquisado) {
  if(tamVetor == 0) {
    cout << "Vetor vazio!" << endl;
    return false;
  }

  for(int i = 0; i < tamVetor; i++) {
    int aux = vetor[i];

    if(aux == pesquisado) {
      cout << "Valor encontrado!" << endl;
      return true;
    }
  }

  cout << "Valor não encontrado!" << endl;
  return false;
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

/*
 * Função buscaSeq: pesquisa, de forma binária,
 * se um determinado valor está cadastrado no vetor de entrada
 * @param vetor[]: vetor de números inteiros
 * @param tamVetor: indica a qtd de elementos registrados no vetor
 * @param pesquisado: valor a ser pesquisado no vetor
 * 
 * @return true: caso o valor pesquisado seja encontrado
 * @return false: se o valor não for encontrado
 */
bool buscaBin(int vetor[], int tamVetor, int pesquisado) {
  if(tamVetor == 0) {
    cout << "Vetor vazio!" << endl;
    return false;
  }

  int esq = 0, dir = tamVetor - 1, meio;

  while(esq <= dir) {
    meio = (esq + dir) / 2;
    if(vetor[meio] == pesquisado) {
      cout << "Valor encontrado!" << endl;
      return true;
    } else if(vetor[meio] > pesquisado) {
      dir = meio - 1;
    } else {
      esq = meio + 1;
    }
  }

  cout << "Valor não encontrado" << endl;
  return false;
}

int main(int argc, char ** argv) {
  int vetor[] = {5, 3, 2, 1, 4, 0, -1, 12, 6};
  bubbleSort(vetor, 9);
  cout << toString(vetor, 9) << endl;
  /* Testar busca Sequencial     
  buscSeq(vetor, 9, pesquisado);*/

  int pesquisado;
  cout << "Digite o valor a ser pesquisado: ";
  cin >> pesquisado;

  cout << "Procurando " << pesquisado << endl;
  // Testar busca binária
  buscaBin(vetor, 9, pesquisado);

  return 0;
}