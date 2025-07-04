#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool higher(char a, char b)
{
    return a > b;
}

string findSub(string inputNumber)
{
    string maxNum, minNum;
    sort(inputNumber.begin(), inputNumber.end());
    minNum = inputNumber;

    sort(inputNumber.begin(), inputNumber.end(), higher);
    maxNum = inputNumber;

    int sub = stoi(maxNum) - stoi(minNum);
    string subNum = to_string(sub);
    return subNum;
}

int main()
{
    string inputNum;
    cin >> inputNum;
    string subNum = findSub(inputNum);

    while (subNum != inputNum)
    {
        inputNum = subNum;
        subNum = findSub(inputNum);
    }

    cout << subNum << endl;
    return 0;
}