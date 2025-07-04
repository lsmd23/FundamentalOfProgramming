#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int type;
    double income, tax;
    double bound;
    cin >> type >> income;

    switch (type)
    {
    case 1:
        bound = 17850;
        break;
    case 2:
        bound = 23900;
        break;
    case 3:
        bound = 29750;
        break;
    case 4:
        bound = 14875;
        break;
    default:
        break;
    }

    if (income > bound)
    {
        tax = bound * 0.15 + (income - bound) * 0.28;
    }
    else
    {
        tax = income * 0.15;
    }
    cout << fixed << setprecision(6) << tax << endl;
}
