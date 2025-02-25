#include "my.h"

struct studentai {
    string v, pav;
    vector <double> hw;
    int egz;
    double paz_m, paz_avrg;
} ;
//----------------------------------------------------------------------------------------------------
static void atsakymas ()
{
    cout << left<< setw(15)<<"Pavarde" << left<<setw(15)<<"Vardas" << left << setw(18) << "Galutinis (vid.)" << "Galutinis (med.)" << endl;
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

static void pazymys_median(studentai& A)
{
    double med = median(A);
    A.paz_m = 0.4 * med + 0.6 * A.egz;
}
static void pazymys_average(studentai& A)
{
    double vidu = average(A);
    A.paz_avrg = 0.4 * vidu + 0.6 * A.egz;
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
 static void iv4(vector<studentai>& grupe)
 {
     int kiek_paz;
     double nd;
     studentai B;
     ifstream fd("kursiokai.txt");
        if (!fd)
     {
         cout << "Failed to open file!" << endl;
     }
     

     string antrastes;
     getline(fd, antrastes);

     while (fd>>B.v>>B.pav)
     {   
         kiek_paz = 0;
         while (fd>>nd)
         {
             B.hw.push_back(nd);
             if (fd.peek() == '\n')
                 break;
             kiek_paz++;
         }
        
         if (kiek_paz > 0)
         {
             B.egz = B.hw[kiek_paz - 1];
             B.hw.pop_back();
         }
         pazymys_average(B);
         pazymys_median(B);
       grupe.push_back(B);

     }
    
     fd.close();
 }

//------------------------------------------------------------------------------------------------------

int main()
{
    vector <studentai> grupe;
    int iv = 0; //??
    char output;
    studentai  A;
    vector <string> vardai = { "Emile", "Greta", "Haroldas", "Guste", "Paulius", "Aleksas", "Kristina", "Aidas", "Vasare", "Diana"};
    vector <string> pavardes = { "Jonaitis", "Pavardaite", "Pavardenis", "Adomaitis", "Lapaite", "Apuokas", "Karalaite", "Nausediene"};
    srand(time(NULL));
    while (iv != 5)
    {
        cout << "Pasirink, kokiu budu bus ivedami studento duomenys" << endl;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes," << endl;
        cout << "4 - skaityti duomenis is failo, 5 - baigti darba " << endl;
        cin >> iv;
        if (iv == 1)
        {
            iv1(A);
            pazymys_average(A);
            pazymys_median(A);

            grupe.push_back(A);
        }
        else if (iv == 2)
        {
            iv2(A);
            pazymys_average(A);
            pazymys_median(A);

            grupe.push_back(A);
        }
        else if (iv == 3)
        {
            iv3(A, vardai, pavardes);
            pazymys_average(A);
            pazymys_median(A);

            grupe.push_back(A);
        }
        else if (iv == 4)
        {
            iv4(grupe);
        }
        else {
            cout << "Pasirinkite, kur norite isvesti duomenis: i ekrana - e, i faila - f" << endl;
            cin >> output;
            if (output == 'f')
            {
                ofstream fr("results.txt");
                atsakymas();
                for (const auto& A : grupe) {
                    fr << left << setw(15) << A.v;
                    fr << left << setw(15) << A.pav;
                    fr << left << setw(18) << fixed << setprecision(2) << A.paz_avrg;
                    fr << fixed << setprecision(2) << A.paz_m << endl;
                }
                fr.close();
            }
            else
            {
                atsakymas();
                for (const auto& A : grupe) {
                    cout << left << setw(15) << A.v;
                    cout << left << setw(15) << A.pav;
                    cout << left << setw(18) << fixed << setprecision(2) << A.paz_avrg;
                    cout << fixed << setprecision(2) << A.paz_m << endl;
                }
            }
        }
    }
    return 0;
}


