// Cas 8, ponavljanje casova 5-7: u svakoj funkciji je jedna greska sa memorijom.
// Pokazati jednu po jednu (ostale pozive u main-u zakomentarisati).
// Ucenik PRVO procita kod i kaze gdje je greska i sta ce se desiti,
// pa tek onda Fn+F5 i  bash ../testiraj.sh ponavljanje.cpp
#include <iostream>
using namespace std;

int* Veci(int a, int b) {
    int veci = a > b ? a : b;
    return &veci;
    // int* veci = new int (a > b ? a : b);
    // return veci;
}

void Program1() {
    int* p = Veci(3, 8);
    cout << *p << endl;
}

void Program2() {
    int* niz = new int[2] { 1, 2 };
    int trenutno = 2;
    int* novi = new int[trenutno + 1];
    for (int i = 0; i < trenutno; i++) novi[i] = niz[i];
    novi[trenutno] = 3;
    
    // delete[] niz;

    niz = novi;
    trenutno++;
    for (int i = 0; i < trenutno; i++) cout << niz[i] << " ";
    cout << endl;
    delete[] niz;
}

void Program3() {
    int* niz = new int[2] { 1, 2 };
    int trenutno = 2;
    int* novi = new int[trenutno + 1];
    delete[] niz;
    for (int i = 0; i < trenutno; i++) novi[i] = niz[i];
    novi[trenutno] = 3;

    // delete[] niz;

    niz = novi;
    trenutno++;
    for (int i = 0; i < trenutno; i++) cout << niz[i] << " ";
    cout << endl;
    delete[] niz;
}

void Program4() {
    int niz[5];
    int* trenutno = new int(0);
    niz[*trenutno] = 42;
    // *trenutno++;
    
    (*trenutno)++;

    cout << niz[0] << endl;
    delete trenutno;
}

int main() {
    // Program1();
    // Program2();
    // Program3();
    Program4();
    return 0;
}
