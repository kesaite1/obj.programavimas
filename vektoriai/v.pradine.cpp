#include "my.h"
#include "code.h"

int main()
{
    // string filename;
    vector <studentai> grupe;
    int iv = 0, sorting = 0; //??
    string isvestis;
    studentai  A;
    vector <string> vardai = { "Emile", "Greta", "Haroldas", "Guste", "Paulius", "Aleksas", "Kristina", "Aidas", "Vasare", "Diana" };
    vector <string> pavardes = { "Jonaitis", "Pavardaite", "Pavardenis", "Adomaitis", "Lapaite", "Apuokas", "Karalaite", "Nausediene" };
    ofstream laiko_failas("laikas.txt");
    srand(time(NULL));
    while (iv != 5)
    {
        try {
            cout << "Pasirink, kokiu budu bus ivedami studento duomenys\n";
            cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentu vardus, pavardes,\n";
            cout << "4 - skaityti duomenis is failo, 5 - baigti darba\n";
            cin >> iv;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                throw  invalid_argument("Neteisinga ivestis! Iveskite skaiciu nuo 1 iki 5.");
            }
            if (iv < 1 || iv > 5)
            {
                throw out_of_range("Neteisinga ivestis! Iveskite skaiciu nuo 1 iki 5.");
            }
            if (iv == 1)
            {
                iv1(A);
                pazymys_vidurkis(A);
                pazymys_mediana(A);

                grupe.push_back(A);
            }
            else if (iv == 2)
            {
                iv2(A);
                pazymys_vidurkis(A);
                pazymys_mediana(A);

                grupe.push_back(A);
            }
            else if (iv == 3)
            {
                iv3(A, vardai, pavardes);
                pazymys_vidurkis(A);
                pazymys_mediana(A);

                grupe.push_back(A);
            }
            else if (iv == 4)
            {
                /*cout << "Iveskite failo pavadinima tokiu formatu pavadinimas.txt: ";
                cin >> filename;
                cout << "Iveskite irasu skaiciu faile: ";
                cin << dydis;*/
                double time1 = iv4(grupe);
                // double time2 = iv4(grupe, "studentai100000.txt");
                // double time3 = iv4(grupe, "studentai1000000.txt");

                // laiko_failas << "Skaitant faila studentai10000.txt programos vykdymo laikas yra: " << time1 << endl;
                // laiko_failas << "Skaitant faila studentai100000.txt programos vykdymo laikas yra: " << time2 << endl;
                //laiko_failas << "Skaitant faila studentai1000000.txt programos vykdymo laikas yra: " << time3 << endl;
                // laiko_failas << "Laiku vidurkis: " << (time1 ) / 1<< endl;
            }
            else {
                while (true) {
                    try {
                        cout << "Pasirinkite, kaip norite rikiuoti duomenis:\n ";
                        cout << "1 - vardai abeceles tvarka,\n";
                        cout << "2 - pavardes abeceles tvarka,\n";
                        cout << "3 - galutini vidurkio pazymiai didejimo tvarka,\n";
                        cout << "4 - galutiniai vidurkio pazymiai mazejimo tvarka,\n";
                        cout << "5 - galutiniai medianos pazymiai didejimo tvarka,\n";
                        cout << "6 - galutiniai medianos pazymiai mazejimo tvarka\n";
                        cin >> sorting;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            throw invalid_argument(" Neteisinga ivestis! Iveskite skaiciu nuo 1 iki 6.");
                        }
                        if (sorting < 1 || sorting > 6) {

                            throw out_of_range(" Neteisinga ivestis! Iveskite skaiciu nuo 1 iki 6.");
                        }
                        if (sorting == 1)
                        {
                            sort(grupe.begin(), grupe.end(), [](const studentai& A, const studentai& B) { return raide(A.v) < raide(B.v); });
                        }
                        else if (sorting == 2)
                        {
                            sort(grupe.begin(), grupe.end(), [](const studentai& A, const studentai& B) { return raide(A.pav) < raide(B.pav); });
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
                        break;
                    }
                    catch (const invalid_argument& e) { cerr << "Klaida:" << e.what() << endl; }
                    catch (const out_of_range& e) { cerr << "Klaida:" << e.what() << endl; }
                }
                while (true) {
                    try {
                        cout << "Pasirinkite, kur norite isvesti duomenis: i ekrana - e, i faila - f\n";
                        cin >> isvestis;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            throw invalid_argument(" Neteisinga ivestis! Iveskite raide e arba f.");
                        }
                        if (isvestis != "f" && isvestis != "e") {

                            throw out_of_range(" Neteisinga ivestis! Iveskite raide e arba f.");
                        }
                        if (isvestis == "f")
                        {
                            ofstream sp("pazangus.txt");
                            ofstream sn("nepazangus.txt");

                            sp << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(18) << "Galutinis (vid.)" << "Galutinis (med.)\n";
                            sp << "-----------------------------------------------------------------" << endl;
                            sn << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(18) << "Galutinis (vid.)" << "Galutinis (med.)\n";
                            sn << "-----------------------------------------------------------------\n";
                            for (const auto& A : grupe) {
                                if (A.paz_vid >= 5 || A.paz_m >= 5)
                                {
                                    sp << left << setw(15) << A.v;
                                    sp << left << setw(15) << A.pav;
                                    sp << left << setw(18) << fixed << setprecision(2) << A.paz_vid;
                                    sp << fixed << setprecision(2) << A.paz_m << endl;
                                }
                                else
                                {
                                    sn << left << setw(15) << A.v;
                                    sn << left << setw(15) << A.pav;
                                    sn << left << setw(18) << fixed << setprecision(2) << A.paz_vid;
                                    sn << fixed << setprecision(2) << A.paz_m << endl;
                                }
                            }
                            sp.close();
                            sn.close();
                            break;
                        }
                        else
                        {
                            cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(18) << "Galutinis (vid.)" << "Galutinis (med.)\n";
                            cout << "-----------------------------------------------------------------\n";
                            cout << "Pazangus studentai: \n";
                            cout << "-----------------------------------------------------------------\n";
                            for (const auto& A : grupe) {
                                if (A.paz_vid >= 5 || A.paz_m >= 5)
                                {
                                    cout << left << setw(15) << A.v;
                                    cout << left << setw(15) << A.pav;
                                    cout << left << setw(18) << fixed << setprecision(2) << A.paz_vid;
                                    cout << fixed << setprecision(2) << A.paz_m << endl;
                                }
                            }
                            cout << "-----------------------------------------------------------------\n";
                            cout << "Nepazangus studentai: \n";
                            cout << "-----------------------------------------------------------------\n";
                            for (const auto& A : grupe) {
                                if (A.paz_vid < 5 && A.paz_m < 5)
                                {
                                    cout << left << setw(15) << A.v;
                                    cout << left << setw(15) << A.pav;
                                    cout << left << setw(18) << fixed << setprecision(2) << A.paz_vid;
                                    cout << fixed << setprecision(2) << A.paz_m << endl;
                                }
                            }
                            break;
                        }
                    }
                    catch (const invalid_argument& e) { cerr << "Klaida: " << e.what() << endl; }
                    catch (const out_of_range& e) { cerr << "Klaida: " << e.what() << endl; }
                }
            }
        }
        catch (const invalid_argument& e) { cerr << "Klaida: " << e.what() << endl; }
        catch (const out_of_range& e) { cerr << "Klaida: " << e.what() << endl; }
    }
        laiko_failas.close();
        return 0;
}

    


