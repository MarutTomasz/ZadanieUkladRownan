#ifndef UKLAD_ROWNAN_L
#define UKLAD_ROWNAN_L

#include "Wektor.hh"
#include "MacierzKw.hh"


class UkladRownanL{
  MacierzKw A; // Ax = b
  Wektor b;
public:
  const Wektor & rozwiaz();
  UkladRownanL();
  UkladRownanL(const MacierzKw & M, const Wektor & W);
  const Wektor & zwroc_wektor_wolny();
  void zmien_wektor_wolny(const Wektor & W);
  //analoginczie dla macierzy
};

/* operator >>
   operator << */


#endif
