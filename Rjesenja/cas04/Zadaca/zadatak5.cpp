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
    rezultat[0] = '?';
    rezultat[1] = '?';
    rezultat[2] = '\0';

    if (imePrezime == nullptr) return;

    bool pronadjenPrvi = false;
    bool pronadjenDrugi = false;

    for (int i = 0; imePrezime[i] != '\0'; ++i) {
        if (imePrezime[i] != ' ') {
            if (!pronadjenPrvi) {
                rezultat[0] = toupper(imePrezime[i]);
                pronadjenPrvi = true;
            } else if (!pronadjenDrugi && i > 0 && imePrezime[i - 1] == ' ') {
                rezultat[1] = toupper(imePrezime[i]);
                pronadjenDrugi = true;
                break;
            }
        }
    }

    if (!pronadjenDrugi) {
        rezultat[1] = '?';
    }
}

void Inicijali2(const char* imePrezime, char rezultat[3]) {
    rezultat[0] = '?';
    rezultat[1] = '?';
    rezultat[2] = '\0';

    if (imePrezime == nullptr || imePrezime[0] == '\0') return;

    rezultat[0] = toupper(imePrezime[0]);

    int indexRazmaka = -1;

    for (int i = 1; imePrezime[i] != '\0'; ++i) {
        if (imePrezime[i] == ' ') {
            indexRazmaka = i;
            break;
        }
    }

    if (indexRazmaka != -1 && imePrezime[indexRazmaka + 1] != '\0') {
        rezultat[1] = toupper(imePrezime[indexRazmaka + 1]);
    }
}

int main() {
    char in[3] = "";
    Inicijali2("Amina Buric", in);
    cout << in << endl;          // AB
    Inicijali2("amar macic", in);
    cout << in << endl;          // AM
    Inicijali2("Madonna", in);
    cout << in << endl;          // M?
    return 0;
}
