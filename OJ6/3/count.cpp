#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string str_in;
    getline(cin, str_in);

    istringstream input(str_in);
    vector<string> sentence, new_sentence;
    string word;

    while (input >> word)
    {
        sentence.push_back(word);
    }

    for (auto it = sentence.begin(); it != sentence.end(); it++)
    {
        bool put_flag = false;
        for (auto it2 = new_sentence.begin(); it2 != new_sentence.end(); it2++)
        {
            if (*it == *it2)
                put_flag = true;
        }
        if (!put_flag)
        {
            new_sentence.push_back(*it);
        }
    }

    cout << new_sentence.size() << endl;

    return 0;
}