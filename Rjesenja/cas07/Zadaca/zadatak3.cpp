/*
    Cas 7, zadatak 3: ispis za sva tri oblika

    Napisati tijela tri funkcije koje ispisu elemente odvojene razmakom
    i na kraju predju u novi red:
    - void IspisiOblik1(int niz[], int n)    staticki niz vrijednosti
    - void IspisiOblik2(int* niz[], int n)   staticki niz pokazivaca
    - void IspisiOblik3(int* niz, int n)     dinamicki niz

    Za sva tri oblika ispis mora biti:  7 8 9
    Razmisli: kod kojeg oblika treba * ispred elementa i zasto?

    main je gotov; provjeri i sa  bash ../../testiraj.sh zadatak3.cpp
*/
#include <iostream>
using namespace std;

void IspisiOblik1(int niz[], int n) {
    for (int i = 0; i < n; i++)
        cout << niz[i] << " ";
    cout << endl;
}

void IspisiOblik2(int* niz[], int n) {
    for (int i = 0; i < n; i++)
        cout << *niz[i] << " ";
    cout << endl;
}

void IspisiOblik3(int* niz, int n) {
    for (int i = 0; i < n; i++)
        cout << niz[i] << " ";
    cout << endl;
}

int main() {
    int oblik1[5] = { 7, 8, 9 };
    IspisiOblik1(oblik1, 3);                  // 7 8 9

    int* oblik2[5] = { new int(7), new int(8), new int(9) };
    IspisiOblik2(oblik2, 3);                  // 7 8 9
    for (int i = 0; i < 3; i++) delete oblik2[i];

    int* oblik3 = new int[3] { 7, 8, 9 };
    IspisiOblik3(oblik3, 3);                  // 7 8 9
    delete[] oblik3;
    return 0;
}
