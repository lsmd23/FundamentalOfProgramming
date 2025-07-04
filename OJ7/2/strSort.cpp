#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string inputStr, outputStr;
    getline(cin, inputStr);

    for (auto it = inputStr.begin() + 1; it != inputStr.end();)
    {
        if (*it > *inputStr.begin())
        {
            // char ch = *it;
            outputStr.push_back(*it);
            inputStr.erase(it);
        }
        else
        {
            it++;
        }
    }

    outputStr.push_back(*inputStr.begin());
    inputStr.erase(inputStr.begin());

    sort(inputStr.begin(), inputStr.end());
    for (auto it = inputStr.begin(); it != inputStr.end(); it++)
    {
        outputStr.push_back(*it);
    }

    cout << outputStr << endl;
    return 0;
}