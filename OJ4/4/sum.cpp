#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int *Fibonacci(int n)
{
    int *fib = new int[n];
    fib[0] = 1;
    fib[1] = 2;

    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}

int main()
{
    int n;
    cin >> n;
    double sum = 0;
    int *Fib = Fibonacci(n + 1);
    for (int i = 0; i < n; i++)
    {
        sum += (double)Fib[i + 1] / Fib[i];
    }
    cout << fixed << setprecision(2) << sum << endl;

    delete[] Fib;
    return 0;
}