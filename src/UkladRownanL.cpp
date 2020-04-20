#include "UkladRownanL.hh"

#include <iomanip>
using std::setprecision;
using std::fixed;
using std::defaultfloat;

UkladRownanL::UkladRownanL() {
  MacierzKw M;
  Wektor W;
  (*this).set_A(M);
  (*this).set_b(W);
}

UkladRownanL::UkladRownanL(const MacierzKw & M, const Wektor & W) {
  (*this).set_A(M);
  (*this).set_b(W);
}

void UkladRownanL::set_A(const MacierzKw &M) {
  (*this).A = M;
}

void UkladRownanL::set_b(const Wektor &W){
  (*this).b = W;
  
}

const MacierzKw & UkladRownanL::get_A() const{
  return (*this).A;
}

const Wektor & UkladRownanL::get_b() const{
  return (*this).b;
}

std::istream & operator >> (std::istream &strm, UkladRownanL &U){
  MacierzKw M;
  Wektor W;
  cin >> M >> W;
  U.set_A(M);
  U.set_b(W);
  
  return strm;
}

std::ostream & operator << (std::ostream &strm, const UkladRownanL &U){
  MacierzKw M = U.get_A();
  Wektor W = U.get_b();
  cout << fixed;
  cout << setprecision(2);
  cout << "| " << M[0] << " | |x_1|   | " << W[0] << " |" << endl;
  cout << "| " << M[1] << " | |x_2| = | " << W[1] << " |" << endl;
  cout << "| " << M[2] << " | |x_3|   | " << W[2] << " |" << endl;
  cout << defaultfloat;
  return strm;
}

Wektor UkladRownanL::rozwiaz() const{
  double epsilon = 0.000000001;
  double wyznacznik_A = (*this).A.wyznacznik(Laplace);
  
  if (abs(wyznacznik_A) < epsilon){
    cerr << "Macierz osobliwa, nie da sie rozwiazac metoda Cramera" << endl;
    exit(1);
  }
  
  
  MacierzKw Kopia = (*this).A;
  Kopia.zmien_kolumne(0,(*this).b);
  double wyznacznik_X1 = Kopia.wyznacznik(Laplace);
  
  Kopia = (*this).A;
  Kopia.zmien_kolumne(1,(*this).b);
  double wyznacznik_X2 = Kopia.wyznacznik(Laplace);
  
  Kopia = (*this).A;
  Kopia.zmien_kolumne(2,(*this).b);
  double wyznacznik_X3 = Kopia.wyznacznik(Laplace);  
  
  Wektor Rozwiazanie(wyznacznik_X1/wyznacznik_A,wyznacznik_X2/wyznacznik_A,wyznacznik_X3/wyznacznik_A);
  return Rozwiazanie;
}
