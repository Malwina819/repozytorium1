#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

float temp1(float x, float a, float b)
{
    float T_1 = a * x + b;
    return T_1;
}

float temp2(float x, float c, float d) {
    float T_2 = c * x + d;
    return T_2;
}

using namespace std;

int main()
{
    float L1;
    float L2;
    float T1;
    float T2;
    float k1;
    float k2;
    int n1;
    int n2;
    string unit;
    string plik_we;
    string plik_wy;

    cout << "Podaj nazwe pliku wejsciowego: ";
    cin >> plik_we;
    cout << "Podaj nazwe pliku wyjsciowego: ";
    cin >> plik_wy;


    ifstream plik;

    plik.open(plik_we);
    plik >> L1 >> unit;
    plik >> L2 >> unit;
    plik >> k1 >> unit;
    plik >> k2 >> unit;
    plik >> T1 >> unit;
    plik >> T2 >> unit;
    plik >> n1;
    plik >> n2;
    plik.close();

    float k = k1 / k2;
    float dT = T2 - T1;
    float a = dT / (L1 + k * L2);
    float b = T1;
    float c = k * a;
    float d = T2 - c * (L1 + L2);


    float dx1 = L1 / n1;
    float dx2 = L2 / n2;


    vector<float> x1(n1 + 1);
    x1[0] = 0.0f;
    for (int i = 1; i <= n1; ++i)
    {
        x1[i] = x1[i - 1] + dx1;
    }

    vector<float> T_1(n1 + 1);
    for (int i = 0; i <= n1; ++i)
    {
        T_1[i] = temp1(x1[i], a, b);
    }

    vector<float> x2(n2 + 1);
    x2[0] = L1;
    for (int i = 1; i <= n2; ++i) {
        x2[i] = L1 + i * dx2;
    }

    vector<float> T_2(n2 + 1);
    for (int i = 0; i <= n2; ++i) {
        T_2[i] = temp2(x2[i], c, d);
    }

    float xk = L1 + L2;


    ofstream plik1(plik_wy, ofstream::trunc);
    plik1 << left;
    plik1 << scientific << setprecision(3);
    plik1 << setw(15) << "x [m]" << setw(15) << "T [K]" << endl;


    for (int i = 0; i <= n1; i++)
    {
        plik1 << setw(15) << x1[i]
            << setw(15) << T_1[i]
            << endl;
    }

    for (int i = 1; i <= n2; i++)
    {
        plik1 << setw(15) << x2[i]
            << setw(15) << T_2[i]
            << endl;
    }

    plik1.close();

}