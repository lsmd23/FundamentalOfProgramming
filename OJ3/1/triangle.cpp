#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double array[3];
    double max = 0;
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> array[i];
        sum += array[i];
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    if (max >= (sum - max))
    {
        cout << "NO" << endl;
    }
    else
    {
        double S = sqrt((sum / 2) * ((sum / 2) - array[0]) * ((sum / 2) - array[1]) * ((sum / 2) - array[2]));
        cout << fixed << setprecision(6) << ((S + S) / max) << endl;
    }

    return 0;
}