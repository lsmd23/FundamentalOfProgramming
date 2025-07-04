#include <iostream>
using namespace std;

int main()
{
    int grade;
    cin >> grade;
    int rank = grade / 10;
    if (grade > 99)
    {
        rank = 9;
    }
    switch (rank)
    {
    case 9:
    {
        cout << 'A' << endl;
        break;
    }
    case 8:
    {
        cout << 'B' << endl;
        break;
    }
    case 7:
    {
        cout << 'C' << endl;
        break;
    }
    case 6:
    {
        cout << 'D' << endl;
        break;
    }
    default:
    {
        cout << 'F' << endl;
        break;
    }
    }

    return 0;
}