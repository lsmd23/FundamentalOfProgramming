#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    char num15[3];
    int num = 0;

    for (int i = 2; i >= 0; i--)
    {
        cin >> num15[i];
        if (num15[i] > 47 && num15[i] < 58) // 0-9
        {
            num += (num15[i] - 48) * pow(15, i);
        }
        else // A-E
        {
            num += (num15[i] - 55) * pow(15, i);
        }
    }

    int num7[4];
    for (int i = 3; i >= 0; i--)
    {
        num7[i] = num % 7;
        num = (int)num / 7;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << num7[i];
    }
    return 0;
}