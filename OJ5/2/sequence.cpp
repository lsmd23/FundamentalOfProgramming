#include <iostream>
using namespace std;

int Sequence(int n)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (n == 1)
        return 3;
    else
        return 4 * Sequence(n - 1) - Sequence(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << Sequence(n) << endl;
    return 0;
}