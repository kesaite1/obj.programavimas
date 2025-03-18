
#ifndef CODE_H   
#define CODE_H   
#include "my.h"

struct studentai {
    string v, pav;
    deque <double> hw;
    int egz;
    double paz_m, paz_vid;
};

static double vidurkis(studentai& A);
static double mediana(studentai& A);
void pazymys_mediana(studentai& A);
void pazymys_vidurkis(studentai& A);
void iv1(studentai& A);
void iv2(studentai& A, mt19937& gen);
void iv3(studentai& A, deque <string>& vardai, deque <string>& pavardes, mt19937& gen);
double iv4(deque<studentai>& grupe, ofstream& laiko_failas);
string raide(string vardai);
void generavimas(string failas, int dydis);
double generavimo_laikas(string& filename, ofstream& laiko_failas);
double apdorojimo_laikas(high_resolution_clock::time_point start, high_resolution_clock::time_point end);

#endif