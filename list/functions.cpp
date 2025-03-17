#include "my.h"
#include "code.h"

bool abc_vardai(const studentai& A, const studentai& B) { return raide(A.v) < raide(B.v); }
bool abc_pavardes(const studentai& A, const studentai& B) { return raide(A.pav) < raide(B.pav); }
bool did_vid(const studentai& A, const studentai& B) { return A.paz_vid < B.paz_vid; }
bool maz_vid(const studentai& A, const studentai& B) { return A.paz_vid > B.paz_vid; }
bool did_med(const studentai& A, const studentai& B) { return A.paz_m < B.paz_m; }
bool maz_med(const studentai& A, const studentai& B) { return A.paz_m > B.paz_m; }


static double vidurkis(studentai& A)
{
    double suma = 0;
	int sk;
    sk = A.hw.size();
    for (list<double>::iterator it = A.hw.begin(); it != A.hw.end(); ++it)
    {
        suma += *it;
    }
    return (sk > 0) ? suma / sk : 0;
}
//-------------------------------------------------------------------------------------------
static double mediana(studentai& A)
{
	double suma = 0;
    int sk;
    sk = A.hw.size();
    sort(A.hw.begin(), A.hw.end());
    if (sk == 0) return 0;
    if (sk % 2 == 0)
    {
		for (int i = 0; i < (sk / 2) - 2; i++)
		{
			A.hw.pop_front();
            A.hw.pop_back();
		}
        for (list<double>::iterator it = A.hw.begin(); it != A.hw.end(); ++it)
        {
            suma += *it;
        }
		return suma / 2.0;
    }
    else
    {
		for (int i = 0; i < (sk / 2); i++)
		{
			A.hw.pop_front();
            A.hw.pop_back();
		}
        return *A.hw.begin();
    }
}
//-------------------------------------------------------------------------------------------
void pazymys_mediana(studentai& A)
{
    A.paz_m = 0.4 * mediana(A) + 0.6 * A.egz;
}
//-------------------------------------------------------------------------------------------
void pazymys_vidurkis(studentai& A)
{
    A.paz_vid = 0.4 * vidurkis(A) + 0.6 * A.egz;
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
void iv2(studentai& A, mt19937& gen)
{
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> A.v >> A.pav;
    uniform_int_distribution<int> egz(1, 10);
    A.egz = egz(gen);
    uniform_int_distribution<int> kiek(1, 50);
    for (int i = 0; i < kiek(gen); i++)
    {
		uniform_real_distribution<double> nd(1.0, 10.0);
		A.hw.push_back(nd(gen));
    }
}
//------------------------------------------------------------------------------------------
void iv3(studentai& A, list <string>& vardai, list <string>& pavardes, mt19937& gen)
{
    uniform_int_distribution<int> kiek_v(0, vardai.size() - 1);
    uniform_int_distribution<int> kiek_pav(0, pavardes.size() - 1);
    uniform_int_distribution<int> egz(1, 10);
    uniform_int_distribution<int> kiek(1, 50);
    uniform_real_distribution<double> nd(1.0, 10.0);
    list<string>::iterator vard = next(vardai.begin(), kiek_v(gen));
    A.v = *vard;
    list<string>::iterator pavard = next(vardai.begin(), kiek_v(gen));
    A.pav = *pavard;
    A.egz = egz(gen);
   
    for (int i = 0; i < kiek(gen); i++)
    {
        A.hw.push_back(nd(gen));
    }
}
//-------------------------------------------------------------------------------------------
double iv4(list<studentai>& grupe, ofstream& laiko_failas)
{
    string choose, filename;
    //int kiek_paz;
    double nd, glaikas, flaikas, skaitymo_laikas;
    studentai B;
    try {
        cout << "Pasirinkite: generuoti nauja faila - g, ar skaityti is egzistuojancio - e: ";
        cin >> choose;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument(" Neteisinga ivestis! Iveskite raide g arbe e.");
        }

        if (choose != "g" && choose != "e" && choose != "G" && choose != "E") {

            throw out_of_range(" Neteisinga ivestis! Iveskite raide g arbe e.");
        }
    }
    catch (const invalid_argument& e) { cerr << "Klaida: " << e.what() << endl; }
    catch (const out_of_range& e) { cerr << "Klaida: " << e.what() << endl; }
    cout << "Iveskite failo pavadinima tokiu formatu: pavadinimas.txt: ";
    cin >> filename;
    
        if (choose == "g") {

           glaikas = generavimo_laikas(filename, laiko_failas);
        }
       
        auto skaitymo_start = high_resolution_clock::now();
        ifstream fd(filename);
        if (!fd)
        {
            cout << "Nepavyko atidaryti failo!\n";
        }
        string antrastes;
        getline(fd, antrastes);
        while (fd >> B.v >> B.pav)
        {
            B.hw.clear();
            //kiek_paz = 0;
            while (fd >> nd)
            {
                B.hw.push_back(nd);
                if (fd.peek() == '\n')
                    break;
               //kiek_paz++;
            }
           // if (kiek_paz > 0)
            
                B.egz = B.hw.back();
                B.hw.pop_back();
            
            pazymys_vidurkis(B);
            pazymys_mediana(B);
            grupe.push_back(B);
        }
        auto skaitymo_end = high_resolution_clock::now();
        skaitymo_laikas = apdorojimo_laikas(skaitymo_start, skaitymo_end);
        laiko_failas << "Duomenu skaitymo is failo laikas: " << skaitymo_laikas << endl;
        
        if (choose == "g") {

            flaikas = skaitymo_laikas + glaikas;
        }
        else flaikas = skaitymo_laikas;
       
        fd.close();
        return flaikas;
}
//------------------------------------------------------------------------------------------------------------------
string raide(string vardai)
{
    transform(vardai.begin(), vardai.end(), vardai.begin(), ::tolower);
    return vardai;
}
//------------------------------------------------------------------------------------------------------------------------
void generavimas(string failas, int dydis)
{
    random_device rd;  
    mt19937 gen(rd());
    uniform_int_distribution<int> sk(1, 50);
    uniform_real_distribution<double> nd(1.0, 10.0);
    uniform_int_distribution<int> egz(1, 10);
    ofstream file(failas);
 
    for (int i = 0; i < dydis; i++)
    {
        file << left << setw(20) << ("Vardas" + to_string(i)) << left << setw(20) << ("Pavarde" + to_string(i));
        
        for (int j = 0; j < sk(gen); j++)
        {
            file << fixed << setprecision(2) << left << setw(5) << nd(gen);
        }
        file << egz(gen) << endl;
    }
    file.close();
}
//------------------------------------------------------------------------------------------------------------------------  
double generavimo_laikas(string& filename, ofstream& laiko_failas)
{
    int dydis;
    cout << "Iveskite irasu skaiciu faile: ";
    cin >> dydis;
	duration<double> skirtumas;

        auto start = high_resolution_clock::now();
        generavimas(filename, dydis);
        auto end = high_resolution_clock::now();
        skirtumas = end - start;
    laiko_failas << "Failo generavimo laikas: " << skirtumas.count() << endl;
    return skirtumas.count();
}


//------------------------------------------------------------------------------------------------------------------------
double apdorojimo_laikas(high_resolution_clock::time_point start, high_resolution_clock::time_point end)
{
    duration<double> skirtumas = end - start;
    return skirtumas.count();
}