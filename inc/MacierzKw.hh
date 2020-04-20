#ifndef MACIERZKW
#define MACIERZKW

#include "rozmiar.h"
#include "Wektor.hh"

enum Wyz_Metoda {Sarrus, Laplace, Gauss};
enum Odw_Metoda {Gauss_Jordan, Definicja};

// IMPLEMENTACJA WEKTOROW JAKO WIERSZY MACIERZY !!

class MacierzKw {
  Wektor tab[ROZMIAR];
  void przestaw_kolumny(int index1, int index2);
  double wyznacznik2_2(int index1, int index2) const; // prowizorka dla 3x3
  MacierzKw macierz_dopelnien () const;  // prowizorka dla 3x3
  
public:
  // Metody sluzace jako set i get
  Wektor & operator[] (int index);
  const Wektor & operator[] (int index) const;

  // Konstruktory  
  MacierzKw();
  MacierzKw(Wektor A, Wektor B, Wektor C);
  
  // Operacje matematyczne
  MacierzKw operator +(const MacierzKw &M) const;
  MacierzKw operator -(const MacierzKw &M) const;
  MacierzKw operator *(const MacierzKw &M) const; 
  MacierzKw operator *(double liczba) const;
  Wektor operator *(const Wektor &W) const;
  
  // Operacje porownania
  bool operator == (const MacierzKw &M) const;
  bool operator != (const MacierzKw &M) const;

  // Metody macierzowe
  double wyznacznik(Wyz_Metoda metoda) const; //Laplace, Gauss, Sarrus
  MacierzKw odwroc(Odw_Metoda metoda) const; //Definicja, Gauss_Jordan
  void przestaw_wiersze(int index1, int index2);
  void transponuj();
  void zmien_wiersz(int index, const Wektor W);
  void zmien_kolumne(int index, const Wektor W);  
};

// Wyswietlanie i wczytywanie
std::istream & operator >> (std::istream &strm, MacierzKw &M);
std::ostream & operator << (std::ostream &strm, const MacierzKw &M);

// Operacja matematyczna
MacierzKw operator *(double liczba, const MacierzKw &M);

// Funkjca macierzowa
MacierzKw MacierzJednostkowa(); 

#endif
