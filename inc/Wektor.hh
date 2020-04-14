#ifndef WEKTOR
#define WEKTOR

#include "rozmiar.h"
#include <math.h>

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;


/**************************************************
 * Deklaracja klasy Wektor o n-wymiarach,         *
 * zawierajaca wszystkie metody konieczne do      *
 * przeprowadzania dzialan na wektorach oraz      *
 *  modyfikacji tych wektorow.                    *
 **************************************************/
class Wektor {
  double tab[ROZMIAR];
  
public:
  // Metody sluzace jako set i get
  double & operator [] (int index);
  const double & operator [] (int index) const;
  
  // Konstruktory
  Wektor();
  Wektor(double xx,double yy, double zz);
  Wektor(double *tablica);

  // Operacje matematyczne
  Wektor operator + (const Wektor &W) const;
  Wektor operator - (const Wektor &W) const;
  double operator * (const Wektor &W) const;
  Wektor operator * (double liczba) const;
  Wektor operator / (double liczba) const;

  // Operacje porownania
  bool operator == (const Wektor &W) const;
  bool operator != (const Wektor &W) const;

  // Metody wektorowe
  double dlugosc() const;
};

// Wyswietlanie i wczytywanie
std::ostream & operator << (std::ostream &strm, const Wektor &W);
std::istream & operator >> (std::istream &strm, Wektor &W);

// Operacja matematyczna
Wektor operator * (double liczba, const Wektor &W);


#endif
