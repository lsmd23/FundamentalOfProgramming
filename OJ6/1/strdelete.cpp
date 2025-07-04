#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    char ch;
    cin >> ch;

    for (auto it = str.begin(); it != str.end();)
    {
        if (*it == ch)
        {
            it = str.erase(it);
        }
        else
        {
            ++it;
        }
    }

    if (str.empty())
    {
        cout << '\0' << endl;
    }
    else
        cout << str << endl;
    return 0;
}
