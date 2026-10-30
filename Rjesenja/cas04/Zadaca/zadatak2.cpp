/*
    Cas 4, zadatak 2: GenerisiID (format sa ispita 2024-07-15)

    Napisati tijelo funkcije string GenerisiID(int broj) koja vraca ID
    u formatu sa ispita: broj se dopuni nulama do 4 cifre, a nule i broj
    su odvojeni crticom. Kad broj vec ima 4 cifre, nema ni nula ni crtice.

    Primjeri:
        GenerisiID(3)     -> ID#000-3
        GenerisiID(14)    -> ID#00-14
        GenerisiID(156)   -> ID#0-156
        GenerisiID(1798)  -> ID#1798

    Koristiti: to_string, length() i petlju koja dodaje nule.
*/
#include <iostream>
#include <string>
using namespace std;

string GenerisiID(int broj) {
    // rjesenje ovdje

    return "";
}

int main() {
    cout << GenerisiID(3) << endl;      // ID#000-3
    cout << GenerisiID(14) << endl;     // ID#00-14
    cout << GenerisiID(156) << endl;    // ID#0-156
    cout << GenerisiID(1798) << endl;   // ID#1798
    return 0;
}
