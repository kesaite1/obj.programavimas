#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::fixed;
using std::setprecision;

struct studentai {
    string v, pav;
   // vector <float> hw;
    float hw;
    int egz;
};

int main()
{
   // vector <studentai> grupe;
    studentai grupe;
    int n, k;
    float ndd, suma, paz;
    //studentai A;
    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter student's name and surname: ";
        cin >> grupe.v >> grupe.pav;
        cout << "Enter the number of marks the student has from homework: ";
        cin >> k;
        cout << "Enter the student's marks from the homework: "<<endl;
        suma = 0;

        for (int i = 0; i < k; i++)
        {
            cin >> ndd;
            suma = suma + ndd;
        }
        grupe.hw = suma / k;
        cout << "Enter student's mark from exam: ";
        cin >> grupe.egz;

        paz = 0.4 * grupe.hw + 0.6 * grupe.egz;

        cout << fixed<<setprecision(2)<<"The student's final mark is: " <<paz<< endl;

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

