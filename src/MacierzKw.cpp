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
std::istream & operator >> (std::istream &strm, MacierzKw &M) {
  for (int i=0; i < ROZMIAR; i++)
    cin >> M[i];
  M.transponuj();
  return strm;
}

std::ostream & operator << (std::ostream &strm, const MacierzKw &M) {
  for (int i=0; i < ROZMIAR; i++)
    cout << M[i] << endl;
  return strm;
}

/********** OPERACJE MATEMATYCZNE **********/
MacierzKw MacierzKw::operator + (const MacierzKw &M) const {
  MacierzKw Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik [i] = tab[i] + M[i];
  return Wynik;
}

MacierzKw MacierzKw::operator - (const MacierzKw &M) const {
  MacierzKw Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik [i] = tab[i] - M[i];
  return Wynik;
}

MacierzKw MacierzKw::operator *(const MacierzKw &M) const {
  MacierzKw Wynik;
  MacierzKw KopiaM = M;
  KopiaM.transponuj();
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++)
      Wynik[i][j] = tab[i] * KopiaM[j];
  return Wynik;
}

MacierzKw MacierzKw::operator *(double liczba) const {
  MacierzKw Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik[i] = tab[i] * liczba;
  return Wynik;
}

Wektor MacierzKw::operator *(const Wektor &W) const {
  Wektor Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik[i] = tab[i] * W;
  return Wynik;
}

MacierzKw operator *(double liczba, const MacierzKw &M) {
  MacierzKw Wynik;
  for (int i=0; i < ROZMIAR; i++)
    Wynik[i] = M[i] * liczba;
  return Wynik;
}

/********** OPERACJE POROWNANIA  **********/
bool MacierzKw::operator == (const MacierzKw &M) const {
  double epsilon = 0.000001;
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++)
      if(abs(tab[i][j] - M[i][j]) > epsilon)
	return false;
  return true;
}

bool MacierzKw::operator != (const MacierzKw &M) const {
  if( *this == M)
    return false;
  return true;
}

/********** METODY MACIERZOWE **********/
// Zamiana miejscami dwoch wybranych wierszy macierzy
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

// Zamiana miejscami dwoch wybranych kolumn macierzy
void MacierzKw::przestaw_kolumny(int index1, int index2) {
  (*this).transponuj();
  (*this).przestaw_wiersze(index1,index2);
  (*this).transponuj();
}

// Metoda pozwalajaca na transponowanie macierzy
void MacierzKw::transponuj() {
  MacierzKw Kopia = (*this);
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++)
      tab[j][i] = Kopia[i][j];
 }

// Metoda pozwalajaca na oblicznie wyznacznikow roznymi metodami
double MacierzKw::wyznacznik(Wyz_Metoda metoda) const {
  double wyznacznik;
  MacierzKw P = *this;
  switch(metoda){
  case Gauss: {
    int k;
    double epsilon = 0.000000001;
    int zmian_miejsc = 1;
    wyznacznik = 1;
    for(int i=0; i < ROZMIAR; i ++){
      k = i+1;
      while(abs(P[i][i]) < epsilon){  // Uzyskiwanie wartosci roznej od 0
	if(k >= ROZMIAR)         // na przekatnej macierzy kwadratowej
	  return 0; 
	P.przestaw_wiersze(i,k++);
	zmian_miejsc *= -1;
      }
      wyznacznik = wyznacznik * P[i][i];    
      P[i] = P[i] / P[i][i];                
      for(int j=i+1; j < ROZMIAR; j++){    // Zerowanie elementow
	P[j] = P[j] - (P[i] * P[j][i]);    // pod przekatna
      }   
    }
    wyznacznik *= zmian_miejsc;
    return wyznacznik;
  }
  case Sarrus: {
    wyznacznik = 0;
    wyznacznik = P[0][0]*P[1][1]*P[2][2] + P[0][1]*P[1][2]*P[2][0]\
               + P[0][2]*P[1][0]*P[2][1] - P[2][0]*P[1][1]*P[0][2]\
               - P[2][1]*P[1][2]*P[0][0] - P[2][2]*P[1][0]*P[0][1];
    return wyznacznik;
  }
  case Laplace: {   // prowizorka dla 3x3
    double wyznacznik = 0;
    wyznacznik += tab[0][0] * (*this).wyznacznik2_2(0,0);
    wyznacznik -= tab[0][1] * (*this).wyznacznik2_2(0,1);
    wyznacznik += tab[0][2] * (*this).wyznacznik2_2(0,2);
    return wyznacznik;
  }
  }
  return 0;
}

double MacierzKw::wyznacznik2_2(int index1, int index2) const{ // prowizorka dla 3x3
  double wyznacznik;
  if (index1 < 0 || index1 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  if (index2 < 0 || index2 >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  
  switch(index1) {
  case 0: {
    switch(index2) {
    case 0: {
      wyznacznik = tab[1][1] * tab[2][2] - tab[2][1] * tab[1][2];
      return wyznacznik;
    }
    case 1: {
      wyznacznik = tab[1][0] * tab[2][2] - tab[2][0] * tab[1][2];
      return wyznacznik;
    }
    case 2: {
      wyznacznik = tab[1][0] * tab[2][1] - tab[2][0] * tab[1][1];
      return wyznacznik;
    }
    }
  }

  case 1:{
    switch(index2) {
    case 0: {
      wyznacznik = tab[0][1] * tab[2][2] - tab[2][1] * tab[0][2];
      return wyznacznik;
    }
    case 1: {
      wyznacznik = tab[0][0] * tab[2][2] - tab[2][0] * tab[0][2];
      return wyznacznik;
    }
    case 2: {
      wyznacznik = tab[0][0] * tab[2][1] - tab[2][0] * tab[0][1];
      return wyznacznik;
    }
    }
  }

  case 2: {
    switch(index2) {
    case 0: {
      wyznacznik = tab[0][1] * tab[1][2] - tab[1][1] * tab[0][2];
      return wyznacznik;
    }
    case 1: {
      wyznacznik = tab[0][0] * tab[1][2] - tab[1][0] * tab[0][2];
      return wyznacznik;
    }
    case 2: {
      wyznacznik = tab[0][0] * tab[1][1] - tab[1][0] * tab[0][1];
      return wyznacznik;
    }
    }
  }
  }
  return 0;
}

// Funkcja pozwalajaca na utworzenie macierzy jednostkowej
MacierzKw MacierzJednostkowa() {
  MacierzKw M;
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++)
      if (i == j)
   	M[i][j] = 1;
  return M;
}

MacierzKw MacierzKw::macierz_dopelnien () const{  // prowizorka dla 3x3
  MacierzKw Dopelnien;
  double znak = 1;
  for (int i=0; i < ROZMIAR; i++)
    for (int j=0; j < ROZMIAR; j++) {
      Dopelnien[i][j] = (*this).wyznacznik2_2(i,j) * znak;
      znak *= -1;
    }
  return Dopelnien;
}


MacierzKw MacierzKw::odwroc(Odw_Metoda metoda) const {
  switch (metoda) {
  case Definicja: {   // wykorzystuje prowizorke dla 3x3
    double epsilon = 0.000000001;
    double wyznacznik;
    MacierzKw Odwrotna;
    MacierzKw Dopelnien;
    
    wyznacznik = (*this).wyznacznik(Sarrus);
    if (abs(wyznacznik) < epsilon){
      cerr << "Macierz osobliwa, nieodwracalna" << endl;
      exit(1);
    }
    
    Dopelnien = (*this).macierz_dopelnien();
    Dopelnien.transponuj();
    
    Odwrotna = (1/wyznacznik) * Dopelnien;
    
    return Odwrotna;
  }

  case Gauss_Jordan: {
    MacierzKw Odwrotna = MacierzJednostkowa();
    MacierzKw P = *this;
    int k;
    double epsilon = 0.000000001;
    for(int i=0; i < ROZMIAR; i ++){
      k = i+1;
      while(abs(P[i][i]) < epsilon){  // Uzyskiwanie wartosci roznej od 0
	if(k >= ROZMIAR){         // na przekatnej macierzy kwadratowej
	  cout << "Macierz jest nieodwracalna, bo jest osobliwa" << endl;
	  exit(1);
	}
	P.przestaw_wiersze(i,k);
	Odwrotna.przestaw_wiersze(i,k);
	k++;
      }
      Odwrotna[i] = Odwrotna[i] / P[i][i];
      P[i] = P[i] / P[i][i];
      
      for(int j=i+1; j < ROZMIAR; j++){  
	Odwrotna[j] = Odwrotna[j] - (Odwrotna[i] * P[j][i]);
	P[j] = P[j] - (P[i] * P[j][i]);
      }   
    }
    
    for(int i = ROZMIAR-1; i > 0; i--) {
      for(int j=0; j < i; j++){  
	Odwrotna[j] = Odwrotna[j] - (Odwrotna[i] * P[j][i]);
	P[j] = P[j] - (P[i] * P[j][i]);
      }   
    }
    
    return Odwrotna;
  } 
  }
  return (*this);
}

void MacierzKw::zmien_wiersz(int index, const Wektor W) {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }   
    tab[index] = W;
}

void MacierzKw::zmien_kolumne(int index, const Wektor W) {
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Poza zakresem" << endl;
    exit(1);
  }
  (*this).transponuj();
  tab[index] = W;
  (*this).transponuj();
}
