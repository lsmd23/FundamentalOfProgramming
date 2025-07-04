#include <iostream>
#include <cmath>
using namespace std;

bool judgePrimeNumber(int n)
{
    int m = sqrt(n);
    bool isPrime = true;
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int main()
{
    int n, sum = 0;
    cin >> n;
    for (int num = 2;; num++)
    {
        if (judgePrimeNumber(num))
        {
            sum += num;
            n--;
        }
        if (!n)
            break;
    }
    cout << sum << endl;
    return 0;
}