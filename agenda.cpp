#include <iostream>
#include <string>

#define TAM 10

using namespace std;
typedef struct contato {
  string nome;
  string whats;
  string email;
  string endereco;
  string dataNasc;
  
  contato() {
  }
  
  ~contato() {
  }

  string toString () {
    return ("[" + nome + ", " + whats + "]");
  }
};

typedef struct agenda {
  contato * contatos = new contato[TAM];
  int qtdContatos;

  agenda () 
  {
    qtdContatos = 0;
  }
  
  void clear() {
    cout << "Limpando a agenda" << endl;
    delete[] contatos;
    qtdContatos = 0;
    contatos = new contato[TAM];
  }

  ~agenda ()
  {
    delete[] contatos;
    contatos = 0;
  }

  void add (contato c)
  {
    contatos[qtdContatos++] = c;
  }

  string toString ()
  {
    if (qtdContatos == 0)
      {
	return "{}";
      }
    string s = "{" + contatos[0].toString ();
    for (int i = 1; i < qtdContatos; i++)
      {
	s += ", " + contatos[i].toString ();
      }
    s += "}";

    return s;
  }
  
  int find(string nome) {
    for(int i = 0; i < qtdContatos; i++) {
        if(contatos[i].nome == nome) {
            return i;
        }
    }
    
    return -1;
  }
  
  contato search(string nome) {
      int index = find(nome);
      if(index != -1) {
          return contatos[index];
      }
      
      return contato();
  }
  
  void rem(string nome) {
      int index = find(nome);
      for(int i = index; i < qtdContatos; i++) {
          contatos[i] = contatos[i + 1];
      }
      qtdContatos--;
  }
  
  void alterar(string nome, contato c) {
      int index = find(nome);
      if(index != -1) {
        contatos[index] = c;
        return;
      }
      
      cout << "Contato ñ encontrado!" << endl;
  }
};

int main () {
  agenda a;

  contato c, c1;
  c.nome = "João";
  c.whats = "(99)98107-7744";
  c.dataNasc = "11/09/1991";
  
  c1.nome = "Pedro";
  c1.whats = "(99)98140-5463";

  a.add (c);
  a.add (c1);
  
  cout << "Agenda" << endl;
  cout << a.toString () << endl;

  contato cSearch = a.search("Léo");
  if(cSearch.nome.size() > 0) {
    cout << cSearch.toString() << endl;    
  } else {
    cout << "Contato ñ encontrado!" << endl;
  }
  
  a.rem("João");
  cout << "Após remover João" << endl;
  cout << a.toString() << endl;
  
  contato novoc;
  novoc.nome = "Livia";
  novoc.whats = "(99)98107-7745";
  a.alterar("Pedro", novoc);
  cout << a.toString() << endl;

  a.clear();
  cout << a.toString () << endl;
  
  return 0;
}
