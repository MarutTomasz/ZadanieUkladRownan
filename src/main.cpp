#include "Wektor.hh"
#include "MacierzKw.hh"
#include "UkladRownanL.hh"
#include "rozmiar.h"

int main() {
  double wyznacznik = 0;
  Wektor W1(-1,1,3);
  Wektor W2(-2,-3,1);
  Wektor W3(1,6,2);

  MacierzKw A(W1, W2, W3);
  wyznacznik = A.wyznacznik(Laplace);
  cout << wyznacznik << endl;

  MacierzKw B = A.odwroc();
  cout << A << endl << endl;
  cout << B << endl << endl;

  MacierzKw C = A * B;
  cout << C << endl;

}
