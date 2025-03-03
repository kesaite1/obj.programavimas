#include "my.h"
#include "code.h"

static double vidurkis(studentai& A)
{
    double suma = 0, sk;
    sk = A.hw.size();
    for (int i = 0; i < sk; i++)
    {
        suma += A.hw[i];
    }
    return (sk > 0) ? suma / sk : 0;
}
//-------------------------------------------------------------------------------------------
static double mediana(studentai& A)
{
    int sk;
    sk = A.hw.size();
    sort(A.hw.begin(), A.hw.end());
    if (sk == 0) return 0;
    if (sk % 2 == 0)  return (A.hw[sk / 2] + A.hw[(sk / 2) - 1]) / 2.0;
    else return A.hw[sk / 2];
}
//-------------------------------------------------------------------------------------------
void pazymys_mediana(studentai& A)
{
    double med = mediana(A);
    A.paz_m = 0.4 * med + 0.6 * A.egz;
}
//-------------------------------------------------------------------------------------------
void pazymys_vidurkis(studentai& A)
{
    double vidu = vidurkis(A);
    A.paz_vid = 0.4 * vidu + 0.6 * A.egz;
}
//-------------------------------------------------------------------------------------------
void iv1(studentai& A)
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
//------------------------------------------------------------------------------------------
void iv2(studentai& A)
{
    double nd;
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> A.v >> A.pav;
    A.egz = rand() % 10 + 1;
    for (int i = 0; i < rand() % 50 + 1; i++)
    {
        nd = 1.0 + (double)rand() / RAND_MAX * 9.0;
        A.hw.push_back(nd);
    }
}
//------------------------------------------------------------------------------------------
void iv3(studentai& A, vector <string>& vardai, vector <string>& pavardes)
{
    double nd;
    A.v = vardai[rand() % vardai.size()];
    A.pav = pavardes[rand() % pavardes.size()];
    A.egz = rand() % 10 + 1;   
    for (int i = 0; i < rand() % 50+1; i++)
    {
        nd = 1.0 + (double)rand() / RAND_MAX * 9.0;
        A.hw.push_back(nd);
    }
}
//-------------------------------------------------------------------------------------------
double iv4(vector<studentai>& grupe)
{
    using namespace std::chrono;
    int kiek_paz, dydis;
    string filename;
    double nd;
    studentai B;
    cout << "Iveskite failo pavadinima tokiu formatu: pavadinimas.txt: ";
    cin >> filename;
    cout << "Iveskite irasu skaiciu faile: ";
    cin >> dydis;
    generavimas(filename, dydis);
    ifstream fd(filename);
    if (!fd)
    {
        cout << "Nepavyko atidaryti failo!" << endl;
        return 0;
    }
    string antrastes;
    getline(fd, antrastes);
    auto start = high_resolution_clock::now();
    while (fd >> B.v >> B.pav)
    {
        B.hw.clear();
        kiek_paz = 0;
        while (fd >> nd)
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
        pazymys_vidurkis(B);
        pazymys_mediana(B);
        grupe.push_back(B);
    }
    auto end = high_resolution_clock::now();
    duration<double> skirtumas = end - start;
    fd.close();

    return skirtumas.count();
}

string raide (string vardai)
{
    transform(vardai.begin(), vardai.end(), vardai.begin(), ::tolower);
    return vardai;
}

void generavimas(string failas, int dydis)
{
    int sk, egz;
    double nd;
    ofstream file(failas);
    for (int i = 0; i < dydis; i++)
    {
        file << left << setw(20) << ("Vardas"+ to_string(i)) << left << setw(20) << ("Pavarde" + to_string(i));
        sk = rand() % 10 + 1;
        for (int j = 0; j < sk; j++)
        {
            nd = 1.0 + (double)rand() / RAND_MAX * 9.0;
            file << fixed << setprecision(2) << left << setw(5) << nd;
        }
        egz = rand() % 10 + 1;
        file << egz << endl;
    }
    file.close();
}