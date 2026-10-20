#include <iostream>     // ubaci biblioteku za ulaz i izlaz (cout, cin)

using namespace std;    // da pišemo cout umjesto std::cout

void funkcija () {
    cout << "Alejkumu selam!" << endl;  // svaka naredba završava sa ;
};

int main() {            // ovdje program počinje
    /*
    cout << "Selam alejkum!" << endl;  // svaka naredba završava sa ;
    funkcija();

    int a = 6;          // ispravno
    int b = 5.5;        // kompajlira se uz upozorenje, ali b je 5: decimale se odsijeku
    //int c{ 5.5 };       // GREŠKA: sa vitičastim zagradama C++ ne dozvoljava gubitak decimala
    // int d = "5";        // GREŠKA: "5" je tekst, a ne broj
    double e = 5;       // ispravno, e je 5.0
    float f = 3.14f;    // slovo f na kraju broja kaže da je to float
    char z = 'A';       // jedan znak ide u jednostruke navodnike
    //char z2 = "A";      // GREŠKA: dvostruki navodnici su tekst, a ne jedan znak
    bool t = 5;         // dozvoljeno: svaki broj osim 0 je true
    int x;              // bez vrijednosti: x sadrži nasumičan broj iz memorije
    const double PDV = 0.17;   // konstanta: kasnije PDV = 0.2; je greška
    // PDV = 0.2; 

    int ab = 'A';       // ako je char njegov decimalni spot se dodjeljuje u int

    cout << "a: " << a << endl; 
    cout << "b: " << b << endl;  
    cout << "e: " << e << endl; 
    cout << "f: " << f << endl; 
    cout << "z: " << z << endl; 
    cout << "t: " << t << endl; 
    cout << "x: " << x << endl; 
    cout << "PDV: " << PDV << endl; 
    
    cout << "ab: " << ab << endl; 
    */
    /*
    int a = 7;
    cout << "Ovo je primjer ispisivanja varijable a: " << a << endl;
    cout << "Zbir: " << a + 3 << ", proizvod: " << a * 3 << "\t";

    int dan, mjesec, godina;
    cin >> dan >> mjesec >> godina;   // korisnik kuca: 5 10 2025 (razmaci ili Enter)
    cout << dan << mjesec << godina << endl;  
    */

    /*
    int bodovi;
    cin >> bodovi;
    if (bodovi < 0 || bodovi > 100)
        cout << "Neispravan unos" << endl;
    else if (bodovi >= 55)             // prag je samo primjer
        cout << "Polozio" << endl;
    else
        cout << "Nije polozio" << endl;

    int broj = 17;
    cout << broj << (broj % 2 == 0 ? " je paran" : " je neparan") << endl;

    int dan = 6;                         // 1 = ponedjeljak ... 7 = nedjelja
    bool radniDan = !(dan == 6 || dan == 7);
    cout << (radniDan ? "radni dan" : "vikend") << endl;
    */

    int ukupnoSekundi;
    cout << "Unesi broj sekundi: ";
    cin >> ukupnoSekundi;

    int sati = ukupnoSekundi / 3600;
    int minute = (ukupnoSekundi % 3600) / 60;
    int sekunde = ukupnoSekundi % 60;

    cout << sati << ":" << minute << ":" << sekunde << endl;

    if (sati >= 8)
        cout << "Radni dan je gotov.\n";
    else
        cout << "Jos " << 8 - sati << " sati rada.\n";

    return 0;
}