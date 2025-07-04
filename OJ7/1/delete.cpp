#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    for (auto it = str.begin(); it != str.end();)
    {
        bool isErase = false;
        for (auto it2 = it + 1; it2 != str.end(); it2++)
        {
            if (*it2 == *it)
            {
                str.erase(it2);
                str.erase(it);
                isErase = true;
                break;
            }
        }
        if (!isErase)
        {
            cout << *it;
            return 0;
            // it++;
        }
    }

    // cout << str;

    return 0;
}