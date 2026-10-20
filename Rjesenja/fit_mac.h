// fit_mac.h - zamjene za ono sto postoji samo u Visual Studiju (MSVC),
// da se ispitni kod kompajlira na Macu i Linuxu (GitHub Codespaces).
// U kod ga ne treba dodavati: F5 i testiraj.sh ga ukljucuju sami.
#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <array>
#include <regex>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <chrono>
#include <functional>
#include <future>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <memory>
#include <utility>
#include <tuple>
#include <any>
#include <optional>
#include <variant>
#include <typeinfo>
#include <exception>
#include <stdexcept>
#include <limits>
#include <cstddef>

// strcpy_s(odrediste, velicina, izvor) i strcpy_s(niz, izvor), kao u Visual Studiju
inline int strcpy_s(char* odrediste, std::size_t velicina, const char* izvor) {
    if (odrediste == nullptr || velicina == 0) return 1;
    if (izvor == nullptr) { odrediste[0] = '\0'; return 1; }
    std::strncpy(odrediste, izvor, velicina - 1);
    odrediste[velicina - 1] = '\0';
    return 0;
}
template<std::size_t N>
inline int strcpy_s(char (&odrediste)[N], const char* izvor) { return strcpy_s(odrediste, N, izvor); }

// strcat_s(odrediste, velicina, izvor) i strcat_s(niz, izvor)
inline int strcat_s(char* odrediste, std::size_t velicina, const char* izvor) {
    if (odrediste == nullptr || izvor == nullptr) return 1;
    std::size_t duzina = std::strlen(odrediste);
    if (duzina >= velicina) return 1;
    std::strncat(odrediste, izvor, velicina - duzina - 1);
    return 0;
}
template<std::size_t N>
inline int strcat_s(char (&odrediste)[N], const char* izvor) { return strcat_s(odrediste, N, izvor); }

// localtime_s(&tm, &time_t): redoslijed parametara kao u Visual Studiju
inline int localtime_s(std::tm* rezultat, const std::time_t* vrijeme) {
    return localtime_r(vrijeme, rezultat) != nullptr ? 0 : 1;
}

// throw exception("poruka") postoji samo u Visual Studiju. Ovdje postaje runtime_error("poruka"),
// koji hvata isti catch (exception& e). Mora biti zadnje, poslije svih #include.
#define exception(poruka) runtime_error(poruka)
