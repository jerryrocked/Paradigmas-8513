#include <iostream>
using namespace std ;
int main() {
  int x,y;
  cout <<"Escriba un número ";
  cin >> x;
  //x = 10;
  y = ++x;
  cout <<"Respuesta " << y;
  cout <<"\n";
  int i;
  i = sizeof( int )*8;
  cout <<"Tamaño (en bits) del tipo int = ";
  cout << i;
  return 0;
}
