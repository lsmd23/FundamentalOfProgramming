#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num;
    cin >> num;
    auto it = num.end();
    do
    {
        it--;
        cout << *it;
    } while (it != num.begin());
    return 0;
}