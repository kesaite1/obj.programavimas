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

static void pazymys(studentai& A, double& vidu, double& med)
{
    vidu = average(A);
    med = median(A);
    if (vidu > med)  A.paz = 0.4 * vidu + 0.6 * A.egz;
    else A.paz = 0.4 * med + 0.6 * A.egz;
}
static void iv1(studentai& A)
{
    double nd;
    string t = "taip";
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> A.v >> A.pav;
    cout << "Iveskite studento egzamino pazymi: ";
    cin >> A.egz;
    
    while (t != "ne")
    {
        cout << "Iveskite studento namu darbu pazymi: ";
        cin >> nd;
        A.hw.push_back(nd);
        cout << " Ar norite testi? (taip/ne): ";
        cin >> t;
    }
}

 static void iv2(studentai & A)
    {
     double nd;
     int kiek;
     cout << "Iveskite studento varda ir pavarde: ";
     cin >> A.v >> A.pav;
     A.egz = rand() % 10 + 1;
     cout << "Kiek pazymiu uz namu darbus turi studentas? ";
     cin >> kiek;
     for (int i=0; i<kiek; i++)
     {
         nd = 1.0 + (double)rand() / RAND_MAX * 9.0;
         A.hw.push_back(nd);
     }

    }

 static void iv3(studentai& A, vector <string> vardai, vector <string> pavardes)
 {
     double nd;
     int kiek;
     A.v = vardai[rand() % vardai.size()];
     A.pav = pavardes[rand() % pavardes.size()];

     A.egz = rand() % 10 + 1;
     cout << "Kiek pazymiu uz namu darbus turi studentas? ";
     cin >> kiek;
     for (int i = 0; i < kiek; i++)
     {
         nd = 1.0 + (double)rand() / RAND_MAX * 9.0;
         A.hw.push_back(nd);
     }
 }

//------------------------------------------------------------------------------------------------------

int main()
{
    vector <studentai> grupe;
    
    int iv = 0; //??
    double vidu, med;
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
        iv1(A);
        pazymys(A, vidu, med);

        grupe.push_back(A);
    }
    else if (iv == 2)
    {
        iv2(A);
        pazymys(A, vidu, med);
        
        grupe.push_back(A);
    }
    else if (iv == 3)
    {
        iv3(A, vardai, pavardes);
        pazymys(A, vidu, med);

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


