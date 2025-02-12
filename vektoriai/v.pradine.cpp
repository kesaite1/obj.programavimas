#include "my.h"

struct studentai {
    string v, pav;
    vector <double> hw;
    int egz;
} ;
//----------------------------------------------------------------------------------------------------
static void atsakymas ()
{
    cout << left<< setw(15)<<"Pavarde" << left<<setw(15)<<"Vardas" << "Galutinis (vid.)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
}
static double average(studentai & A, long n)
{
    double suma = 0, ndd, vid;
    A.hw.clear();
    cout << "Enter the student's marks from the homework: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ndd;
        A.hw.push_back(ndd);
        suma = suma + ndd;
    }
    vid = suma / n;
    return vid;
}
static double median(studentai & A, long n)
{
    sort(A.hw.begin(), A.hw.end());
    if (n % 2 == 0)  return (A.hw[n / 2] + A.hw[(n / 2) - 1]) / 2.0;
    else return A.hw[n / 2];
}
//------------------------------------------------------------------------------------------------------

int main()
{
    vector <studentai> grupe;
    
    int m, n, hw, iv; //m- studentu sk, n- nd sk
    double paz, vidu, med, nd;
    string t;
    studentai  A;
    vector <string> vardai = { "Emile", "Greta", "Haroldas", "Guste", "Paulius", "Aleksas", "Kristina", "Aidas", "Vasare", "Diana"};
    vector <string> pavardes = { "Jonaitis", "Pavardaite", "Pavardenis", "Adomaitis", "Lapaite", "Apuokas", "Karalaite", "Nausediene"};
    srand(time(NULL));
    while (iv!=4)
    { 
    cout << "Pasirink, kokiu budu bus ivedami studentu duomenys" << endl;
    cout << "1 - ranka, 2 - generuoti paşymius, 3 - generuoti ir paşymius ir studentø vardus, pavardes, 4 - baigti darbà " << endl;
    cin >> iv;
    if (iv == 1) 
    { 
    cout << "Iveskite studento varda ir pavarde: ";
        cin >> A.v >> A.pav; 
    cout << "Iveskite studento egzamino pazymi: ";
        cin >> A.egz;
    cout << "Iveskite studento namu darbu pazymius: ";
    while ( t!= "ne")
    {
        cin >> nd;
        A.hw.push_back(nd);
        cout << " Ar norite testi? taip/ne" << endl;
        cin >> t;

        }
    grupe.push_back(A);
    }
    else if (iv == 2)
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
        grupe.push_back(A);
    }
    else if (iv == 3)
    {
        vardai[rand() % vardai.size()];
        A.v.push_back(vardai);
        pavardes[rand() % pavardes.size()];
        A.pav.push_back(pavardes);
        A.egz = rand() % 10 + 1;
        while (t != "ne")
        {
            nd = 1.0 + (double)rand() / RAND_MAX * 9.0;
            A.hw.push_back(nd);
            cout << " Ar norite testi? taip/ne" << endl;
            cin >> t;
        }
        grupe.push_back(A);
    }
    else {

    }    
        vidu = average(A, n);
        med = median(A, n);
       
        if (vidu > med)  paz = 0.4 * vidu + 0.6 * A.egz;
        else paz = 0.4 * med + 0.6 * A.egz;

        atsakymas();
        cout << left << setw(15) << A.pav;
        cout << left << setw(15) << A.v;
        cout << fixed << setprecision(2) << paz << endl;

    }
      
    }
    
    return 0;
}


