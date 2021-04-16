#include <iostream>

using namespace std;

int fat(int num) {
  if(num == 1) {
    return 1;
  } else {
    return num * fat(num - 1);
  }
}

int main(int argc, char const *argv[])
{
  int num;
  cout << "Digite um número p/ cálculo do fatorial: ";
  cin >> num;

  cout << "Fatorial de " << num
       << " = " << fat(num) << endl;

  return 0;
}