#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;

    if (delta > 0)
    {
        double rt1 = (-b + sqrt(delta)) / (2 * a);
        double rt2 = (-b - sqrt(delta)) / (2 * a);
        cout << fixed << setprecision(6) << rt1 << endl
             << rt2 << endl;
    }
    else if (delta == 0)
    {
        double rt = (-b) / (2 * a);
        cout << fixed << setprecision(6) << rt << endl;
    }
    else
    {
        cout << "Error" << endl;
    }

    return 0;
}