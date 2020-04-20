#include "Wektor.hh"

/********** SET I GET **********/
/* Metody pozwalajace na odwolywanie sie do elementow wektora
 * poprzez uzycie nawiasow klamrowych.
 *
 * index - pozycja elementu w tablicy;
 *
 * Warunek wstepny:
 *   index - liczba calkowita z przedzialu [0,ROZMIAR);
 *
 * Warunek koncowy:
 *   brak;
 *
 * Zwracane wartosci:
 *   Wartosc elementu tab[index];
 */
double & Wektor::operator [] (int index) {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

const double & Wektor::operator [] (int index) const {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

/********** KONSTRUKTORY **********/
Wektor::Wektor () {
  for (int i=0; i<ROZMIAR; i++)
    tab[i] = 0;
}

Wektor::Wektor (double xx, double yy, double zz) {
  tab[0] = xx;
  tab[1] = yy;
  tab[2] = zz;
}

Wektor::Wektor (double *tablica) {
  for (int i=0; i<ROZMIAR; i++)
    tab[i] = tablica[i];
}

/********** WCZYTYWANIE I WYSWIETLANIE  **********/
std::istream & operator >> (std::istream &strm, Wektor &W) {
  for (int i=0; i<ROZMIAR; i++)
    cin >> W[i];
  return strm;
}

std::ostream & operator << (std::ostream &strm, const Wektor &W) {
  for (int i=0; i<ROZMIAR; i++)
    cout << W[i] << "  ";
  return strm;
}

/********** OPERACJE MATEMATYCZNE  **********/
Wektor Wektor::operator + (const Wektor &W) const {
  Wektor wynik;
  for (int i=0; i<ROZMIAR; i++)
    wynik[i] = tab[i] + W[i];
  return wynik;
} 

Wektor Wektor::operator - (const Wektor &W) const {
  Wektor wynik;
  for (int i=0; i<ROZMIAR; i++)
    wynik[i] = tab[i] - W[i];
  return wynik;
} 

double Wektor::operator * (const Wektor &W) const {
  double wynik = 0;
  for (int i=0; i<ROZMIAR; i++)
    wynik += tab[i] * W[i];
  return wynik;
}

Wektor Wektor::operator * (double liczba) const{
  Wektor wynik;
  for (int i=0; i<ROZMIAR; i++)
    wynik[i] = tab[i] * liczba;
  return wynik;
}

Wektor Wektor::operator / (double liczba) const{
  Wektor wynik;
  if(liczba == 0)
    exit(1);
  for (int i=0; i<ROZMIAR; i++)
    wynik[i] = tab[i] / liczba;
  return wynik;
}

Wektor operator * (double liczba, const Wektor &W) {
  Wektor wynik;
  for (int i=0; i<ROZMIAR; i++)
    wynik[i] = W[i] * liczba;
  return wynik;
} 

/********** OPERACJE POROWNIANIA  **********/
bool Wektor::operator == (const Wektor &W) const {
  double epsilon = 0.000001;
  for (int i=0; i<ROZMIAR; i++)
    if (abs(tab[i]- W[i]) > epsilon)
      return false;
  return true;
}

bool Wektor::operator != (const Wektor &W) const {
  if (*this == W)
    return false;
  return true;
}

/********** OPERACJE WEKTOROWE  **********/
double Wektor::dlugosc() const{
  double length = 0;
  for (int i=0; i<ROZMIAR; i++)
    length += (tab[i] * tab[i]);
  length = sqrt(length);
  return length;
}
