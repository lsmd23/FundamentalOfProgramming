#include <iostream>
using namespace std;

int main()
{
    int min, max;
    cin >> min >> max;

    int sum = 0;
    for (int i = min; i <= max; i++)
    {
        sum += i * i;
    }

    printf("%d", sum);
    return 0;
}