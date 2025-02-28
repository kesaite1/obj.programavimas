#include "my.h"

struct studentai {
    string v, pav;
    double* hw = nullptr;
    int hw_kiek = 0;
    int egz;
    double paz;
};
//----------------------------------------------------------------------------------------------------
static void atsakymas()
{
    cout << left << setw(15) << "Pavarde" << left << setw(15) << "Vardas" << "Galutinis (vid.)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
}
static double average(studentai& A)
{
    double suma = 0;
    for (int i = 0; i < A.hw_kiek; i++)
    {
        suma += A.hw[i];
    }
    return (A.hw_kiek > 0) ? suma / A.hw_kiek : 0;
}
static double median(studentai& A)
{
    double rezultatas;
    if (A.hw_kiek == 0) return 0;
    
    double* laik = new double[A.hw_kiek];
    for (int i = 0; i < A.hw_kiek; i++)
    {
        laik[i] = A.hw[i];
    }
    sort(laik, laik+A.hw_kiek);
    
    if (A.hw_kiek % 2 == 0)  rezultatas = (laik[A.hw_kiek / 2] + laik[(A.hw_kiek / 2) - 1]) / 2.0;
    else rezultatas = laik[A.hw_kiek / 2];
    delete[]laik;
    return rezultatas;
}

static void pazymys(studentai& A)
{
    double vidu = average(A);
    double med = median(A);
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
        double* new_hw = new double[A.hw_kiek + 1];
        for (int i = 0; i < A.hw_kiek; i++)
        {
            new_hw[i] = A.hw[i];
        }
        new_hw[A.hw_kiek] = nd;
        delete[] A.hw;
        A.hw= new_hw;
        A.hw_kiek++;
        cout << " Ar norite testi? (taip/ne): ";
        cin >> t;
    }
}

static void iv2(studentai& A)
{
    double nd;
    int kiek;
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> A.v >> A.pav;
    A.egz = rand() % 10 + 1;
    cout << "Kiek pazymiu uz namu darbus turi studentas? ";
    cin >> kiek;
    for (int i = 0; i < kiek; i++)
    {
        nd = 1.0 + (double)rand() / RAND_MAX * 9.0;
        double* new_hw = new double[A.hw_kiek + 1];
        for (int i = 0; i < A.hw_kiek; i++)
        {
            new_hw[i] = A.hw[i];
        }
        new_hw[A.hw_kiek] = nd;
        delete[] A.hw;
        A.hw = new_hw;
        A.hw_kiek++;
    }

}

static void iv3(studentai& A, const vector<string>& vardai, const vector<string>& pavardes)
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
        double* new_hw = new double[A.hw_kiek + 1];
        for (int i = 0; i < A.hw_kiek; i++)
        {
            new_hw[i] = A.hw[i];
        }
        new_hw[A.hw_kiek] = nd;
        delete[] A.hw;
        A.hw = new_hw;
        A.hw_kiek++;
    }
}

//------------------------------------------------------------------------------------------------------

int main()
{
    vector<studentai> grupe;
    int iv = 0;
    vector <string> vardai = { "Emile", "Greta", "Haroldas", "Guste", "Paulius", "Aleksas", "Kristina", "Aidas", "Vasare", "Diana" };
    vector <string> pavardes = { "Jonaitis", "Pavardaite", "Pavardenis", "Adomaitis", "Lapaite", "Apuokas", "Karalaite", "Nausediene" };
    srand(time(NULL));
    while (iv != 4)
    {
        cout << "Pasirink, kokiu budu bus ivedami studento duomenys" << endl;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes, 4 - baigti darba " << endl;
        cin >> iv;
        studentai A;
        if (iv == 1)
        {
            iv1(A);
            pazymys(A);

            grupe.push_back(A);
        }
        else if (iv == 2)
        {
            iv2(A);
            pazymys(A);
            
            grupe.push_back(A);
        }
        else if (iv == 3)
        {
            iv3(A, vardai, pavardes);
            pazymys(A);
            
            grupe.push_back(A);
        }
        else {
            atsakymas();
            for (auto& A: grupe) {
                cout << left << setw(15) << A.v;
                cout << left << setw(15) << A.pav;
                cout << fixed << setprecision(2) << A.paz << endl;
                delete[] A.hw;
            }
        }
    }
    return 0;
}

