#include <iostream>
#include <string>

using namespace std;

// Variáveis globais
const int TAM = 10;
string * nomes = new string[TAM];
int size = 0;

// Funções
bool cheio(void) {;
  return size == TAM;
}

void adicionar (void)
{
  if(cheio()) {
    cout << "Vetor Cheio!" << endl;
    return;
  }
  
  cout << "Digite um nome: " << endl;
  string nome;
  cin >> nome;
  nomes[size++] = nome;
}

string toString(void)
{
  if (size == 0) {
    return "{}";
  }
  string s = "{" + nomes[0];
  for (int i = 1; i < size; i++) {
    s += ", " + nomes[i];
  }
  s += "}";

  return s;
}

bool vazio(void) {
  return size == 0;
}
  
int buscar(string nomeProcurado) {
  for(int i = 0; i < size; i++) {
    if(nomes[i] == nomeProcurado) {
      return i;
    }
  }
  
  return -1;
}
  
void remover(string nomeProcurado) {
  if(vazio()) {
    cout << "Vetor vazio!" << endl;
    return;
  }

  int index = buscar(nomeProcurado);
  for(int i = index; i < size; i++) {
      nomes[i] = nomes[i + 1];
  }

  size--;
}
  
void removerInicio(void) {
  if(vazio()) {
    cout << "Vetor vazio!" << endl;
    return;
  }

  for(int i = 0; i < size - 1; i++) {
    nomes[i] = nomes[i + 1];
  }

  nomes[size - 1] = "";
  size--;
}

void removerFim(void) {
  if(vazio()) {
    cout << "Vetor vazio!" << endl;
    return;
  }

  nomes[size - 1] = "";
  size--;
}

int main () {
  for(int i = 0; i < 3; i++) {
    adicionar();
  }
  cout << toString() << endl;

  cout << "Remover Fim: " << endl;
  removerFim();
  cout << toString() << endl;
  
  cout << "Remover Inicio: " << endl;
  removerInicio();
  cout << toString() << endl;
  
  cout << buscar("Emanuelle") << endl;

  return 0;
}