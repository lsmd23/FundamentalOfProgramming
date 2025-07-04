#include <iostream>
using namespace std;

unsigned int AlphaMultiply(unsigned int num)
{
    if (num == 0)
        return 0;
    else if (num < 10)
        return num;
    else
    {
        unsigned int mul = 1;
        while (num != 0)
        {
            mul *= (num % 10 == 0) ? 1 : (num % 10);
            num /= 10;
        }

        return AlphaMultiply(mul);
    }
}

int main()
{
    unsigned int num;
    cin >> num;

    cout << AlphaMultiply(num) << endl;

    return 0;
}