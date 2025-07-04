#include <iostream>

using namespace std;

void strcompress(char *s)
{
    char compress[1000];
    int count[26] = {};
    int j = 0;
    for (int i = 0;; i++)
    {
        if (s[i] == ' ')
        {
            compress[j] = s[i];
            j++;
        }
        else
        {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] == 1 || count[s[i] - 'a'] == 3 || count[s[i] - 'a'] == 6)
            {
                compress[j] = s[i];
                j++;
            }
        }
        if (s[i] == '\0')
        {
            compress[j] = s[i];
            break;
        }
    }
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = '\0';
    }
    for (int i = 0; compress[i] != '\0'; i++)
    {
        s[i] = compress[i];
    }
}

int main()
{
    char s[1000];
    cin.getline(s, 1000);
    strcompress(s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        cout << s[i];
    }
    return 0;
}
