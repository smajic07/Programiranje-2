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
    // rjesenje ovdje

    return "";
}

int main() {
    cout << GenerisiSifru("Amina Buric", 3) << endl;    // AB:2025-003
    cout << GenerisiSifru("Amar Macic", 15) << endl;    // AM:2025-015
    cout << GenerisiSifru("Maid Ramic", 156) << endl;   // MR:2025-156
    cout << GenerisiSifru("maid ramic", 7) << endl;     // MR:2025-007
    return 0;
}
