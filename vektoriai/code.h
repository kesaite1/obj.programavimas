
#ifndef CODE_H   
#define CODE_H   
#include "my.h"

struct studentai {
    string v, pav;
    vector <double> hw;
    int egz;
    double paz_m, paz_vid;
};

static double vidurkis(studentai& A);
static double mediana(studentai& A);
void pazymys_mediana(studentai& A);
void pazymys_vidurkis(studentai& A);
void iv1(studentai& A);
void iv2(studentai& A);
void iv3(studentai& A, vector <string>& vardai, vector <string>& pavardes);
double iv4(vector<studentai>& grupe, string file_name);
string raide(string vardai);

#endif