#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string word1, word2, changed_word1, changed_word2;
    cin >> word1 >> word2;

    for (char ch : word1)
    {
        changed_word1 += tolower(ch);
    }
    for (char ch : word2)
    {
        changed_word2 += tolower(ch);
    }

    int word_count_1[26] = {}, word_count_2[26] = {};
    for (char ch : changed_word1)
    {
        word_count_1[(int)(ch - 97)]++;
    }
    for (char ch : changed_word2)
    {
        word_count_2[(int)(ch - 97)]++;
    }

    bool isAnagrams = true;
    for (int i = 0; i < 26; i++)
    {
        if (word_count_1[i] != word_count_2[i])
        {
            isAnagrams = false;
            break;
        }
    }
    // cout << int('a') << ' ' << int('z') << endl;
    // cout << changed_word1 << ' ' << changed_word2;

    if (isAnagrams)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}