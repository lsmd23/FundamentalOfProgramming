#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <utility>

using namespace std;

bool checkIsNum(string input)
{
    for (char ch : input)
    {
        if (ch < '1' || ch > '9')
            return false;
    }
    return true;
}

bool checkDuplicate(string input)
{
    set<char> helpSet;
    for (char ch : input)
    {
        if (!helpSet.insert(ch).second)
            return true;
    }
    return false;
}

int main()
{
    string input;
    cin >> input;

    if (!checkIsNum(input))
    {
        cout << "no" << endl;
        return 0;
    }
    if (checkDuplicate(input))
    {
        cout << "no" << endl;
        return 0;
    } // 判断基本条件

    vector<pair<int, int>> vec;
    for (char ch : input)
    {
        pair<int, int> elem{(int)(ch - 48), 0};
        vec.push_back(elem);
    }

    auto it = vec.begin();
    do
    {
        int nextPosition = it->first;
        for (int i = 0; i < nextPosition; i++)
        {
            it++;
            if (it == vec.end())
                it = vec.begin();
        } // 按规则找到下一个数

        it->second++;
        if (it->second > 1)
        {
            cout << "no" << endl;
            return 0;
        } // 将该数标记，若已标记过，该数不满足条件，退出代码
    } while (it != vec.begin());

    for (; it != vec.end(); it++)
    {
        if (it->second != 1)
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}