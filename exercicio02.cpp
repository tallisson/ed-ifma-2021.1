#include <iostream>
#include <string>

using namespace std;

template <typename T>
int v(T vetor[]) {
  int s = (int) sizeof(*vetor) / sizeof(*vetor[0]);

  return s;
}

int main(int argc, char ** argv) {
  double vetor[] = {1.1, 2.2, 3.3, 10.1};
  cout << v(&vetor) << endl;
  return 0;
}