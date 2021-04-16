#include <iostream>

using namespace std;

int sum(int num) {
  if(num == 1) {
    return 1;
  } else {
    return num + sum(num - 1);
  }
}

int main(int argc, char const *argv[])
{
  int num;
  cout << "Digite um número: ";
  cin >> num;

  cout << "Somatória de " << num
       << " = " << sum(num) << endl;

  return 0;
}