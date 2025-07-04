#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double sale, rate;
    cin >> sale >> rate;

    double tax = sale * rate;

    cout << fixed << setprecision(2) << tax;

    return 0;
}