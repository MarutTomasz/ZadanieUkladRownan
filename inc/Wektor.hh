#ifndef WEKTOR
#define WEKTOR

#define ROZMIAR 3
#include <math.h>

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

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
  const Wektor operator + (const Wektor &W2) const;
  const Wektor operator - (const Wektor &W2) const;
  const double operator * (const Wektor &W2) const;
  const Wektor operator * (double l2) const;
  const Wektor operator / (double l2) const;

  // Operacje porownania
  bool operator == (const Wektor &W2) const;
  bool operator != (const Wektor &W2) const;

  // Metody wektorowe
  double dlugosc() const;
};

// Wyswietlanie i wczytywanie
std::ostream & operator << (std::ostream &strm, const Wektor &W);
std::istream & operator >> (std::istream &strm, Wektor &W);

// Operacja matematyczna
Wektor operator * (double l1,const Wektor &W2);


#endif
