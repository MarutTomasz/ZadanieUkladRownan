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
/* Funkcja pozwalajaca na wczytywanie wartosci ze strumienia do wektora.
 *
 * strm - strumien z ktorego czytamy dane
 * W - wektor na ktory zapisujemy dane
 *
 * Warunek wstepny:
 *   strm - zainicjowany strumien wejsciowy;
 *
 * Warunek koncowy:
 *   Strumien strm nie zostal zepsuty;
 *
 * Zwracane wartosci:
 *   Wskaznik na strumien strm;
 */
std::istream & operator >> (std::istream &strm, Wektor &W) {
  for (int i=0; i<ROZMIAR; i++)
    cin >> W[i];
  return strm;
}

/* Funkcja pozwalajaca na wypisywanie wartosci wektora na strumien.
 *
 * strm - strumien na ktory wrzucamy dane
 * W - wektor z ktorego czytamy dane
 *
 * Warunek wstepny:
 *   strm - zainicjowany strumien wyjsciowy;
 *
 * Warunek koncowy:
 *   Nastapilo wyswietlenie komunikatu;
 *
 * Zwracane wartosci:
 *   Wskaznik na strumien strm;
 */
std::ostream & operator << (std::ostream &strm, const Wektor &W) {
  for (int i=0; i<ROZMIAR; i++)
    cout << W[i] << "  ";
  return strm;
}

/********** OPERACJE MATEMATYCZNE  **********/
/* Metody i funkcje przeciazajace operatory dzialan matematycznych.
 *
 * W - zawiera jeden z argeumentow operacji artmentycznej w 
 *                     postaci wektora;
 * liczba - zawiera jeden z argumentow operacji artmetycznej w 
 *                     postaci liczby skalarnej;
 *
 * Warunek wstepny:
 *   W przypadku operacji dzielenia, zmienna liczba musi byc 
 *                     rozna od 0;   
 *
 * Warunek koncowy:
 *   brak;
 *
 * Zwracane wartosci:
 *   Wynik operacji artmentycznej;
 */
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
/* Metody pozwalajace na porownywanie dwoch wektorow.
 *
 * W - jeden z argumentow operacji porownania
 *
 * Warunek wstepny:
 *   Zgodne typy argumentow;   
 *
 * Warunek koncowy:
 *   brak;
 *
 * Zwracane wartosci:
 *   False lub true, wynik operacji porownania;
 */
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
/* Metoda zwracajaca dlugosc wektora.
 *
 * Warunek wstepny:
 *   brak;
 *
 * Warunek koncowy:
 *   brak;
 *
 * Zwracane wartosci:
 *   Wartosc oznaczajaca dlugosc wektora;
 */
double Wektor::dlugosc() const{
  double length = 0;
  for (int i=0; i<ROZMIAR; i++)
    length += (tab[i] * tab[i]);
  length = sqrt(length);
  return length;
}
