#ifndef MACIERZKW
#define MACIERZKW

#include "rozmiar.h"
#include "Wektor.hh"

enum Wyz_Metoda {Sarrus, Laplace, Gauss};
enum Odw_Metoda {Gaus_Jordan, Definicja};

// IMPLEMENTACJA WEKTOROW JAKO WIERSZY MACIERZY !!

class MacierzKw {
  Wektor tab[ROZMIAR];
      //MacierzKw dopelnienie(int x, int y);  - tylko jesli znamy juz szablony

public:
  // Metody sluzace jako set i get
  Wektor & operator[] (int index);
  const Wektor  & operator[] (int index) const;

  // Konstruktory  
  MacierzKw();
  MacierzKw(Wektor A, Wektor B, Wektor C);
  // MacierzKw(double *tablica);
  // MacierzKw(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9);
  
  // Operacje matematyczne
  const MacierzKw operator +(const MacierzKw &B) const; //1
  const MacierzKw operator -(const MacierzKw &B) const; //1
  const MacierzKw operator *(const MacierzKw &B) const; //1
  const MacierzKw operator *(double B) const; //1
  const Wektor operator *(const Wektor &B) const;
  
  // Operacje porownania
  bool operator == (const MacierzKw &W2) const;
  bool operator != (const MacierzKw &W2) const;

  // Metody macierzowe
  const MacierzKw transponuj() const;
  //void transponuj();

  const MacierzKw odwroc() const;
  //void odwroc(); //z definicji, gauss

  double wyznacznik(Wyz_Metoda metoda) const; //laplace, gauss, sarrusa

  void przestaw_wiersze(int index1, int index2);
  void przestaw_kolumny(int index1, int index2);
};
// Wyswietlanie i wczytywanie
std::istream & operator >> (std::istream &strm, MacierzKw &A);
std::ostream & operator << (std::ostream &strm, const MacierzKw &A);

// Operacja matematyczna
const MacierzKw operator *(double B, const MacierzKw &M);

// Funkjca macierzowa
MacierzKw MacierzJednostkowa();



#endif
