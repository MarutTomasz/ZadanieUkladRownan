#include "Wektor.hh"
#include "MacierzKw.hh"
#include "UkladRownanL.hh"
#include "rozmiar.h"

int main() {
  double wyznacznik = 0;
  Wektor W1(0,1,1);
  Wektor W2(2,3,1);
  Wektor W3(1,1,2);

  MacierzKw A(W1, W2, W3);
  wyznacznik = A.wyznacznik(Sarrus);
  cout << wyznacznik << endl;
}
