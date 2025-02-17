#include "my.h"

struct studentai {
    string v, pav;
    vector <double> hw;
    int egz;
    double paz;
} ;
//----------------------------------------------------------------------------------------------------
static void atsakymas ()
{
    cout << left<< setw(15)<<"Pavarde" << left<<setw(15)<<"Vardas" << "Galutinis (vid.)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
}
static double average(studentai & A)
{
    double suma = 0,sk;
    sk = A.hw.size();
    for (int i = 0; i < sk; i++)
    {
        suma += A.hw[i];
    }
    return (sk > 0) ? suma / sk : 0;
}
static double median(studentai & A)
{
    int sk;
    sk = A.hw.size();
    sort(A.hw.begin(), A.hw.end());
    if (sk == 0) return 0;
    if (sk % 2 == 0)  return (A.hw[sk / 2] + A.hw[(sk / 2) - 1]) / 2.0;
    else return A.hw[sk / 2];
}

void pazymys(double& vidu, double& med)
{
    vidu = average(A);
    med = median(A);
    if (vidu > med)  A.paz = 0.4 * vidu + 0.6 * A.egz;
    else A.paz = 0.4 * med + 0.6 * A.egz;
}
void iv1(studentai& A, int t, int nd)
{
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> A.v >> A.pav;
    cout << "Iveskite studento egzamino pazymi: ";
    cin >> A.egz;
    cout << "Iveskite studento namu darbu pazymius: ";
    while (t != "ne")
    {
        cin >> nd;
        A.hw.push_back(nd);
        cout << " Ar norite testi? taip/ne" << endl;
        cin >> t;
    }
}

 void iv2(studentai & A, int t, int nd)
    {
     cout << "Iveskite studento varda ir pavarde: ";
     cin >> A.v >> A.pav;
     A.egz = rand() % 10 + 1;
     while (t != "ne")
     {
         nd = 1.0 + (double)rand() / RAND_MAX * 9.0;
         A.hw.push_back(nd);
         cout << " Ar norite testi? taip/ne" << endl;
         cin >> t;
     }

    }

 void iv3(studentai& A, int t, int nd)
 {
     A.v = vardai[rand() % vardai.size()];
     A.pav = pavardes[rand() % pavardes.size()];

     A.egz = rand() % 10 + 1;
     while (t != "ne")
     {
         nd = 1.0 + (double)rand() / RAND_MAX * 9.0;
         A.hw.push_back(nd);
         cout << " Ar norite testi? taip/ne" << endl;
         cin >> t;
     }
 }

//------------------------------------------------------------------------------------------------------

int main()
{
    vector <studentai> grupe;
    
    int iv = 0;
    double vidu, med, nd;
    string t = "taip";
    studentai  A;
    vector <string> vardai = { "Emile", "Greta", "Haroldas", "Guste", "Paulius", "Aleksas", "Kristina", "Aidas", "Vasare", "Diana"};
    vector <string> pavardes = { "Jonaitis", "Pavardaite", "Pavardenis", "Adomaitis", "Lapaite", "Apuokas", "Karalaite", "Nausediene"};
    srand(time(NULL));
    while (iv!=4)
    { 
    cout << "Pasirink, kokiu budu bus ivedami studento duomenys" << endl;
    cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba " << endl;
    cin >> iv;
    if (iv == 1) 
    { 
        iv1(A, t, nd);
        pazymys(vidu, med);
       /* vidu = average(A);
        med = median(A);
        if (vidu > med)  A.paz = 0.4 * vidu + 0.6 * A.egz;
        else A.paz = 0.4 * med + 0.6 * A.egz;*/

    grupe.push_back(A);
    }
    else if (iv == 2)
    {
        iv2(A,t,nd);
        pazymys(vidu, med);
        /*vidu = average(A);
        med = median(A);
        if (vidu > med)  A.paz = 0.4 * vidu + 0.6 * A.egz;
        else A.paz = 0.4 * med + 0.6 * A.egz;*/
        grupe.push_back(A);
    }
    else if (iv == 3)
    {
        iv3(A,t,nd);
        pazymys(vidu, med);
        /*vidu = average(A);
        med = median(A);
        if (vidu > med)  A.paz = 0.4 * vidu + 0.6 * A.egz;
        else A.paz = 0.4 * med + 0.6 * A.egz;*/
        grupe.push_back(A);
    }
    else {  
        atsakymas();
        for (const auto& A : grupe) {
            cout << left << setw(15) << A.v;
            cout << left << setw(15) << A.pav;
            cout << fixed << setprecision(2) << A.paz << endl;
        }


    }    

    }
      
    
    return 0;
}


