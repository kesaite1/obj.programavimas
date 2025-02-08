#include "my.h"

struct studentai {
    string v, pav;
   // vector <float> hw;
    float hw;
    int egz;
} A;
void atsakymas ()
{
    cout << left<< setw(15)<<"Pavarde" << left<<setw(15)<<"Vardas" << "Galutinis (vid.)" << endl;
    cout << "-----------------------------------------------------------------" << endl;

}
int main()
{
   // vector <studentai> grupe;
   // studentai grupe;
    int n, k;
    float ndd, suma, paz;
    //studentai A;
    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter student's name and surname: ";
        cin >> A.v >> A.pav;
        cout << "Enter the number of marks the student has from homework: ";
        cin >> k;
        cout << "Enter the student's marks from the homework: "<<endl;
        suma = 0;

        for (int i = 0; i < k; i++)
        {
            cin >> ndd;
            suma = suma + ndd;
        }
        A.hw = suma / k;
        cout << "Enter student's mark from exam: ";
        cin >> A.egz;

        paz = 0.4 * A.hw + 0.6 * A.egz;
        atsakymas();
        cout << left << setw(15) << A.pav;
        cout << left << setw(15) << A.v;
        cout<< fixed << setprecision(2) << paz << endl;


        //studentai laik;
        // grupe.push_back(laik);
    }
    /*for (auto n : grupe) {

        cout << n.v << endl;
     }*/

    return 0;
}

/*void readFile(studentai A[])
{
    ifstream fd("duomenys.txt");

    char eil[50];
    for (int i=0; i<n; i++)
    {
        fd.get (eil, 50);
        A.vpav = eil;
        fd >> A.vpav;
    }
}*/

