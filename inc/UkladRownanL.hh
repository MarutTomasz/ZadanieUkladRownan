#ifndef UKLAD_ROWNAN_L
#define UKLAD_ROWNAN_L

#include "Wektor.hh"
#include "MacierzKw.hh"
#include "rozmiar.h"

class UkladRownanL{
  MacierzKw A; // Ax = b
  Wektor b;
public:
  UkladRownanL();
  UkladRownanL(const MacierzKw & M, const Wektor & W);
  
  const MacierzKw & get_A() const;
  const Wektor & get_b() const;
   
  void set_A(const MacierzKw &N);
  void set_b(const Wektor &N);
  
  const Wektor & rozwiaz();
  
  //analoginczie dla macierzy
};

/* operator >>
   operator << */


#endif
