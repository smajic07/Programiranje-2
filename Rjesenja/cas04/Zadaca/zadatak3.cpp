/*
    Cas 4, zadatak 3: koliko puta se rijec pojavljuje u tekstu

    Napisati tijelo funkcije
        int BrojPojavljivanja(const string& tekst, const string& rijec)
    koja vraca koliko puta se rijec pojavljuje u tekstu. Broje se
    pojavljivanja koja se ne preklapaju: poslije svakog nadjenog
    pojavljivanja trazi se dalje od njegovog kraja.

    Primjeri:
        BrojPojavljivanja("ana voli banane i ananas", "ana")  -> 3
        BrojPojavljivanja("C++ je C++", "C++")                 -> 2
        BrojPojavljivanja("abc", "x")                          -> 0

    Koristiti: tekst.find(rijec, odPozicije) u petlji.
    find vraca string::npos kad vise nema pojavljivanja.
*/
#include <iostream>
#include <string>
using namespace std;

int BrojPojavljivanja(const string& tekst, const string& rijec) {
    // rjesenje ovdje

    return 0;
}

int main() {
    cout << BrojPojavljivanja("ana voli banane i ananas", "ana") << endl;   // 3
    cout << BrojPojavljivanja("C++ je C++", "C++") << endl;                 // 2
    cout << BrojPojavljivanja("abc", "x") << endl;                          // 0
    return 0;
}
