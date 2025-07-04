#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i <= std::sqrt(num); i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
bool isPalindrome(int num)
{
    if (num < 0)
        return false;
    int original = num, reversed = 0;
    while (num != 0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}
int main()
{
    int min, max;
    cin >> min >> max;
    for (int i = min; i <= max; i++)
    {
        if (isPrime(i) && isPalindrome(i))
            cout << i << ' ';
    }
    return 0;
}