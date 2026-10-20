#include "fit_mac.h"
using namespace std;

int main() {
    char ime[20];
    strcpy_s(ime, 20, "Amina Buric");
    time_t sada = time(nullptr);
    tm lokalno;
    localtime_s(&lokalno, &sada);
    cout << ime << " " << lokalno.tm_year + 1900 << endl;
    try {
        throw runtime_error("Izuzetak radi");
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
