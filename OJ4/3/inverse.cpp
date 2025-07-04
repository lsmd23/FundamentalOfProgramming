#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    static int binaryNum[32];
    int decimalNum;
    cin >> decimalNum;
    int changedDecimalNum = 0;

    for (int i = 31; i >= 0; i--)
    {
        binaryNum[i] = decimalNum % 2;
        decimalNum /= 2;
    }

    for (int i = 0; i < 16; i++)
    {
        swap(binaryNum[i], binaryNum[i + 16]);
    }

    for (int i = 0; i < 32; i++)
    {
        changedDecimalNum += binaryNum[i] * pow(2, 31 - i);
    }

    cout << changedDecimalNum;
    return 0;
}