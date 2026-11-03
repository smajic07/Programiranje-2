/*
    Cas 4, zadatak 1: GenerisiSifru (ispitna funkcija, 4 boda)

    Napisati tijelo funkcije string GenerisiSifru(string imePrezime, int id)
    koja vraca sifru u formatu  XY:2025-NNN  gdje je:
    - XY velika pocetna slova imena i prezimena (i kad su unesena malim slovima),
    - 2025 fiksna godina,
    - NNN id sa vodecim nulama do tri cifre.

    Primjeri:
        GenerisiSifru("Amina Buric", 3)   -> AB:2025-003
        GenerisiSifru("Amar Macic", 15)   -> AM:2025-015
        GenerisiSifru("Maid Ramic", 156)  -> MR:2025-156
        GenerisiSifru("maid ramic", 7)    -> MR:2025-007

    Pokusaj sam, bez gledanja u cas04.cpp.
    Koristiti: find(' '), toupper, to_string i if za vodece nule.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string GenerisiSifru(string imePrezime, int id) {
    char prvoSlovo = toupper(imePrezime[0]);
    size_t razmak = imePrezime.find(' ');
    char drugoSlovo = '?';
    if (razmak != string::npos && razmak + 1 < imePrezime.length()) {
        drugoSlovo = toupper(imePrezime[razmak + 1]);
    }

    string idStr = to_string(id);
    string nnn = "";
    if (idStr.length() == 1) nnn = "00" + idStr;
    else if (idStr.length() == 2) nnn = "0" + idStr;
    else nnn = idStr;

    string rez = "";
    rez += prvoSlovo;
    rez += drugoSlovo;
    rez += ":2025-";
    rez += nnn;

    return rez;
}

int main() {
    cout << GenerisiSifru("Amina Buric", 3) << endl;    // AB:2025-003
    cout << GenerisiSifru("Amar Macic", 15) << endl;    // AM:2025-015
    cout << GenerisiSifru("Maid Ramic", 156) << endl;   // MR:2025-156
    cout << GenerisiSifru("maid ramic", 7) << endl;     // MR:2025-007
    return 0;
}
