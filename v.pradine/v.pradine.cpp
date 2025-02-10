#include "my.h"

struct studentai {
    string v, pav;
    vector <double> hw;
    int egz;
} ;
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

int main()
{
   // vector <studentai> grupe;
   // studentai grupe;
    int m; //m- studentu sk
    long n; //n- nd sk
    double paz, vidu, med;
    cout << "Enter the number of students: ";
    cin >> m;
   

    for (int i = 0; i < m; i++)
    {   
        studentai  A; 
        
        cout << "Enter student's name and surname: ";
        cin >> A.v >> A.pav;
        cout << "Enter the number of marks the student has from homework: ";
        cin >> n;
        vidu = average(A, n);
        med = median(A, n);
        cout << "Enter student's mark from exam: ";
        cin >> A.egz;
        if (vidu>med)  paz = 0.4 * vidu + 0.6 * A.egz;
        else paz = 0.4 * med + 0.6 * A.egz;
       
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


