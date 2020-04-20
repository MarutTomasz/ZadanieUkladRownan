#include "Wektor.hh"
#include "MacierzKw.hh"
#include "UkladRownanL.hh"
#include "rozmiar.h"

int main() {
  Wektor W;
  MacierzKw M;
  
  cin >> M >> W;
  UkladRownanL U(M,W);


  cout << "Uklad rownan do rozwiazania:" << endl;
  cout << U << endl;
  
  cout << "Rozwiazanie x = (x1, x2, x3):" << endl;
  Wektor X = U.rozwiaz();
  cout << X << endl << endl;
  
  Wektor err = M * X - W;
  cout << "Wektor bledu:  Ax-b = (  " << err << ")" << endl;
  cout << "Dlugosc wektora bledu: |Ax-b| = " << err.dlugosc() << endl;

}
