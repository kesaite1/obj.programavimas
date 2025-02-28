#include "my.h"

struct studentai {
    string v, pav;
    vector <double> hw;
    int egz;
    double paz_m, paz_vid;
} ;
//----------------------------------------------------------------------------------------------------
static double vidurkis(studentai & A)
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
    double vidu = vidurkis(A);
    A.paz_vid = 0.4 * vidu + 0.6 * A.egz;
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

 static void iv3(studentai& A, vector <string>& vardai, vector <string>& pavardes)
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
 static double iv4(vector<studentai>& grupe, string file_name)
 {
     using namespace std::chrono;
     int kiek_paz;
     double nd;
     studentai B;
     ifstream fd(file_name);
     if (!fd)
     {
         cout << "Failed to open file!" << endl;
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
         pazymys_average(B);
         pazymys_median(B);
         grupe.push_back(B);
     }
     auto end = high_resolution_clock::now();
     duration<double> skirtumas = end - start;
     fd.close();

     return skirtumas.count();
 }
//-----------------------------------------------------------------------------------------------------
int main()
{
    string file_name;
    vector <studentai> grupe;
    int iv = 0, sorting = 0; //??
    char output;
    studentai  A;
    vector <string> vardai = { "Emile", "Greta", "Haroldas", "Guste", "Paulius", "Aleksas", "Kristina", "Aidas", "Vasare", "Diana"};
    vector <string> pavardes = { "Jonaitis", "Pavardaite", "Pavardenis", "Adomaitis", "Lapaite", "Apuokas", "Karalaite", "Nausediene"};
    ofstream laiko_failas("laikas.txt");
    srand(time(NULL));
    while (iv != 5)
    {
        cout << "Pasirink, kokiu budu bus ivedami studento duomenys" << endl;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes," << endl;
        cout << "4 - skaityti duomenis is failo, 5 - baigti darba " << endl;
        cin >> iv;
        if (iv != 1 && iv != 2 && iv != 3 && iv != 4 && iv != 5)
        {
            cout << "Invalid input!!!" << endl;
            return 0;
        }
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
           // double time1 = iv4(grupe, "studentai10000.txt");
           // double time2 = iv4(grupe, "studentai100000.txt");
           // double time3 = iv4(grupe, "studentai1000000.txt");

           // laiko_failas << "Skaitant faila studentai10000.txt programos vykdymo laikas yra: " << time1 << endl;
           // laiko_failas << "Skaitant faila studentai100000.txt programos vykdymo laikas yra: " << time2 << endl;
           //laiko_failas << "Skaitant faila studentai1000000.txt programos vykdymo laikas yra: " << time3 << endl;
           // laiko_failas << "Laiku vidurkis: " << (time1 ) / 1<< endl;
        }
        else {
            cout << "Pasirinkite, kaip norite rikiuoti duomenis: " << endl;
            cout << "1 - vardai abeceles tvarka," << endl;
            cout << "2 - pavardes abeceles tvarka," << endl;
            cout << "3 - galutini vidurkio pazymiai didejimo tvarka," << endl;
            cout << "4 - galutiniai vidurkio pazymiai mazejimo tvarka," << endl;
            cout << "5 - galutiniai medianos pazymiai didejimo tvarka," << endl;
            cout << "6 - galutiniai medianos pazymiai mazejimo tvarka" << endl;
            cin >> sorting;
            if (sorting == 1)
            {
                sort(grupe.begin(), grupe.end(), [](const studentai& A, const studentai& B) { return A.v < B.v; });
            }
            else if (sorting == 2)
            {
                sort(grupe.begin(), grupe.end(), [](const studentai& A, const studentai& B) { return A.pav < B.pav; });
            }
            else if (sorting == 3)
            {
                sort(grupe.begin(), grupe.end(), [](const studentai& A, const studentai& B) { return A.paz_vid < B.paz_vid; });
            }
            else if (sorting == 4)
            {
                sort(grupe.begin(), grupe.end(), [](const studentai& A, const studentai& B) { return A.paz_vid > B.paz_vid; });
            }
            else if (sorting == 5)
            {
                sort(grupe.begin(), grupe.end(), [](const studentai& A, const studentai& B) { return A.paz_m < B.paz_m; });
            }
            else if (sorting == 6)
            {
                sort(grupe.begin(), grupe.end(), [](const studentai& A, const studentai& B) { return A.paz_m > B.paz_m; });
            }
            cout << "Pasirinkite, kur norite isvesti duomenis: i ekrana - e, i faila - f" << endl;
            cin >> output;
            if (output != 'f' && output != 'e')
            {
                while (output != 'f' && output != 'e')
                {
                    cout << "Invalid input!!!" << endl;
                    cout << "Pasirinkite, kur norite isvesti duomenis: i ekrana - e, i faila - f" << endl;
                    cin >> output;
                }
            }
            if (output == 'f')
            {
                ofstream fr("results.txt");
                fr << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(18) << "Galutinis (vid.)" << "Galutinis (med.)" << endl;
                fr << "-----------------------------------------------------------------" << endl;
                for (const auto& A : grupe) {
                    fr << left << setw(15) << A.v;
                    fr << left << setw(15) << A.pav;
                    fr << left << setw(18) << fixed << setprecision(2) << A.paz_vid;
                    fr << fixed << setprecision(2) << A.paz_m << endl;
                }
                fr.close();
            }
            else
            {
                cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(18) << "Galutinis (vid.)" << "Galutinis (med.)" << endl;
                cout << "-----------------------------------------------------------------" << endl;
                for (const auto& A : grupe) {
                    cout << left << setw(15) << A.v;
                    cout << left << setw(15) << A.pav;
                    cout << left << setw(18) << fixed << setprecision(2) << A.paz_vid;
                    cout << fixed << setprecision(2) << A.paz_m << endl;
                }
            }
        }
    }
    laiko_failas.close();
    return 0;
}


