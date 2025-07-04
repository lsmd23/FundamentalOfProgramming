#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    cin >> word;

    if (word.back() == 'y' && word.length() > 1 &&
        (word[word.length() - 2] != 'a' && word[word.length() - 2] != 'e' &&
         word[word.length() - 2] != 'i' && word[word.length() - 2] != 'o' &&
         word[word.length() - 2] != 'u'))
    {
        word = word.substr(0, word.length() - 1) + "ies";
    }
    else if (word.back() == 's' || word.back() == 'x' ||
             word.back() == 'z' || (word.length() > 1 && word.substr(word.length() - 2) == "ch") ||
             (word.length() > 1 && word.substr(word.length() - 2) == "sh"))
    {
        word += "es";
    }
    else
    {
        word += "s";
    }

    cout << word << endl;
    return 0;
}