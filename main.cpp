#include <iostream>
#include <vector>
using namespace std;

double Interpolacja(double x[], double y[], double punktInter, int lbPunktow) {
    double wynik = 0;
    
    for (int i = 0; i < lbPunktow; i++)
    {
        double tmp = 1;
        for (int j = 0; j < lbPunktow; j++)
        {
            if (i != j)
            {
                tmp *= (punktInter - x[j]) / (x[i] - x[j]);
            }
        }
        wynik += tmp * y[i];
    }
    return wynik;
}

int main()
{
    unsigned int lbPunktow = 0;
    
    cout << "Podaj liczbe znanych punktow: ";
    cin >> lbPunktow;
    
    double *x = new double[lbPunktow];
    double *y = new double[lbPunktow];
    
    for (int i = 0; i < lbPunktow; i++)
    {
        cout << "Podaj x i y dla punktu " << i + 1 << endl;
        cin >> x[i] >> y[i];
    }
    
    double punktInter = 0;
    
    cout << "Podaj punkt do obliczenia: ";
    cin >> punktInter;
    
    double wynik = Interpolacja(x, y, punktInter, lbPunktow);
    
    cout << "Wartosc dla punktu " << punktInter << " wynosi: " << wynik << endl;
    
    delete[] x;
    delete[] y;
    return 0;
}
