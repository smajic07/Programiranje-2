/*
    Cas 4, zadatak 5: Inicijali sa const char*, bez string-a

    Napisati tijelo funkcije
        void Inicijali(const char* imePrezime, char rezultat[3])
    koja u rezultat upise velika pocetna slova imena i prezimena
    i znak '\0' na kraju, da se rezultat moze ispisati kao tekst.
    Ako u tekstu nema razmaka, drugi inicijal je '?'.
    Ne koristiti string, samo char nizove.

    Primjeri:
        "Amina Buric"  -> AB
        "amar macic"   -> AM
        "Madonna"      -> M?

    Koristiti: toupper; razmak naci petljom kroz znakove do '\0'.
*/
#include <iostream>
#include <cctype>
using namespace std;

void Inicijali(const char* imePrezime, char rezultat[3]) {
    // rjesenje ovdje

}

int main() {
    char in[3] = "";
    Inicijali("Amina Buric", in);
    cout << in << endl;          // AB
    Inicijali("amar macic", in);
    cout << in << endl;          // AM
    Inicijali("Madonna", in);
    cout << in << endl;          // M?
    return 0;
}
