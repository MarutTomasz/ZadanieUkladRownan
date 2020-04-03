#include "MacierzKw.hh"

/********** SET I GET  **********/
Wektor & MacierzKw::operator[] (int index) {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

const Wektor  & MacierzKw::operator[] (int index) const {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  return tab[index];
}

/********** KONSTRUKTORY **********/
MacierzKw::MacierzKw() {
  Wektor W;
  for (int i=0; i < ROZMIAR; i++)
    tab[i] = W;  
}

MacierzKw::MacierzKw(Wektor A, Wektor B, Wektor C) {
  tab[0] = A;
  tab[1] = B;
  tab[2] = C;
}

/********** WCZYTYWANIE I WYSWIETLANIE **********/
std::ostream & operator << (std::ostream &strm, const MacierzKw &A) {
  for (int i=0; i < ROZMIAR; i++)
    cout << A[i] << endl;
  return strm;
}

std::istream & operator >> (std::istream &strm, MacierzKw &A) {
  for (int i=0; i < ROZMIAR; i++)
    cin >> A[i];
  return strm;
}

/********** OPERACJE MATEMATYCZNE **********/
const MacierzKw MacierzKw::operator + (const MacierzKw &B) const {
  MacierzKw Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik [i] = tab[i] + B[i];
  return Wynik;
}
  
const MacierzKw MacierzKw::operator - (const MacierzKw &B) const {
  MacierzKw Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik [i] = tab[i] - B[i];
  return Wynik;
}

const MacierzKw MacierzKw::operator *(const MacierzKw &B) const {
  MacierzKw Wynik;
  MacierzKw Trans_B = B.transponuj();
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++)
      Wynik[i][j] = tab[i] * Trans_B[j];
  return Wynik;
}

const MacierzKw MacierzKw::operator *(double B) const {
  MacierzKw Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik[i] = tab[i] * B;
  return Wynik;
}

const Wektor MacierzKw::operator *(const Wektor &B) const {
  Wektor Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik[i] = tab[i] * B;
  return Wynik;
}

const MacierzKw operator *(double B, const MacierzKw &M) {
  MacierzKw Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik[i] = M[i] * B;
  return Wynik;
}

/********** OPERACJE POROWNANIA  **********/
bool MacierzKw::operator == (const MacierzKw &W2) const {
  for (int i=0; i < ROZMIAR; i++)
    if(tab[i] != W2[i])
      return false;
  return true;
}

bool MacierzKw::operator != (const MacierzKw &W2) const {
  if( *this == W2)
    return false;
  return true;
}

/********** METODY MACIERZOWE **********/
void MacierzKw::przestaw_wiersze(int index1, int index2) {
  if (index1 < 0 || index1 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  if (index2 < 0 || index2 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  Wektor pomocniczy = tab[index1];
  tab[index1] = tab[index2];
  tab[index2] = pomocniczy;
}

void MacierzKw::przestaw_kolumny(int index1, int index2) {
  MacierzKw pomocnicza;
  pomocnicza = this->transponuj();
  pomocnicza.przestaw_wiersze(index1,index2);
  *this = pomocnicza.transponuj();
}

const MacierzKw MacierzKw::transponuj() const {
  MacierzKw Transponowana;
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++)
      Transponowana[j][i] = tab[i][j];
  return Transponowana;
}

double MacierzKw::wyznacznik(Wyz_Metoda metoda) const {
  double wyznacznik;
  MacierzKw P = *this;
  switch(metoda){
  case Gauss: {
    int k;
    int zmian = 1;
    wyznacznik = 1;
    for(int i=0; i < ROZMIAR; i ++){
      k = i+1;
      while(P[i][i] == 0){
	if(k >= ROZMIAR)
	  return 0;
	P.przestaw_wiersze(i,k++);
	zmian *= -1;
      }
      wyznacznik = wyznacznik * P[i][i];
      P[i] = P[i] / P[i][i];
      for(int j=i+1; j < ROZMIAR; j++){
	P[j] = P[j] - (P[i] * P[j][i]);
      }   
    }
    wyznacznik *= zmian;
    return wyznacznik;
  }
  case Sarrus: {
    wyznacznik = 0;
    wyznacznik = P[0][0]*P[1][1]*P[2][2]+P[0][1]*P[1][2]*P[2][0]+\
      P[0][2]*P[1][0]*P[2][1]-P[2][0]*P[1][1]*P[0][2]-\
      P[2][1]*P[1][2]*P[0][0]-P[2][2]*P[1][0]*P[0][1];
    return wyznacznik;
  }
  }
  return 4;
  
  
  
}
 

MacierzKw MacierzJednostkowa() {
  MacierzKw M;
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++)
      if (i == j)
   	M[i][j] = 1;
  return M;
}
