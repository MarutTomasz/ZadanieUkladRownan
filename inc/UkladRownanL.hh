#ifndef UKLAD_ROWNAN_L
#define UKLAD_ROWNAN_L

#include "Wektor.hh"
#include "MacierzKw.hh"
#include "rozmiar.h"

class UkladRownanL{
  MacierzKw A; // Ax = b
  Wektor b;

public:
  // Konstruktory  
  UkladRownanL();
  UkladRownanL(const MacierzKw & M, const Wektor & W);
  
  // Metody sluzace jako set i get
  const MacierzKw & get_A() const;
  const Wektor & get_b() const;
  void set_A(const MacierzKw &M);
  void set_b(const Wektor &W);
  
  Wektor rozwiaz() const;
  
};

std::istream & operator >> (std::istream &strm, UkladRownanL &U);
std::ostream & operator << (std::ostream &strm, const UkladRownanL &U);


#endif
