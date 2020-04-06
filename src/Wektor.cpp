#include "Wektor.hh"

/********** SET I GET **********/
// Funkcja pozwala na odnoszenie się do wybranego elementu
// i pozawala na modyfikowanie go.
double & Wektor::operator [] (int index) {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

// Funkca pozwala na odnoszenie się do wybranego elementu,
// ale nie pozwala na modyfikowanie go.
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
// operator pozwalajacy wyswietlac wektor
std::ostream & operator << (std::ostream &strm, const Wektor &W) {
  for (int i=0; i<ROZMIAR; i++)
    cout << W[i] << "  ";
  return strm;
}

// operator pozwalajacy wczytywac wektor
std::istream & operator >> (std::istream &strm, Wektor &W) {
  for (int i=0; i<ROZMIAR; i++)
    cin >> W[i];
  return strm;
}

/********** OPERACJE MATEMATYCZNE  **********/
// operator pozwalajacy na dodawanie wektorow
const Wektor Wektor::operator + (const Wektor &W2) const {
  Wektor W3;
  for (int i=0; i<ROZMIAR; i++)
    W3[i] = tab[i] + W2[i];
  return W3;
} 

// Operator pozwalajacy na odejmowanie wektorow
const Wektor Wektor::operator - (const Wektor &W2) const {
  Wektor W3;
  for (int i=0; i<ROZMIAR; i++)
    W3[i] = tab[i] - W2[i];
  return W3;
} 

// Operator pozwalajacy na mnozenie skalarne wektorow
const double Wektor::operator * (const Wektor &W2) const {
  double wynik = 0;
  for (int i=0; i<ROZMIAR; i++)
    wynik += tab[i] * W2[i];
  return wynik;
}

// Operator pozwalajacy na mnozenie wektora przez liczbe
const Wektor Wektor::operator * (double l2) const{
  Wektor Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i] * l2;
  return Wynik;
}

// Tak jak wyzej, ale argumenty na odwrot
Wektor operator * (double l1,const Wektor &W2) {
  Wektor Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = W2[i] * l1;
  return Wynik;
} 

// Operator pozwalajacy na dzielenie wektora przez liczbe
const Wektor Wektor::operator / (double l2) const{
  Wektor Wynik;
  for (int i=0; i<ROZMIAR; i++)
    Wynik[i] = tab[i] / l2;
  return Wynik;
}

/********** OPERACJE POROWNIANIA  **********/
// Operatory porownania wektorow
bool Wektor::operator == (const Wektor &W2) const {
  for (int i=0; i<ROZMIAR; i++)
    if (tab[i] != W2[i])
      return false;
  return true;
}

bool Wektor::operator != (const Wektor &W2) const {
  if (*this == W2)
    return false;
  return true;
}

/********** OPERACJE WEKTOROWE  **********/
// Metoda zwracajaca dlugosc wektora
double Wektor::dlugosc() const{
  double l = 0;
  for (int i=0; i<ROZMIAR; i++)
    l = l + (tab[i] * tab[i]);
  l = sqrt(l);
  return l;
}




  
