#include <iostream>

using namespace std;

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int main()
{
    char s1[1000], s2[1000];

    cin.getline(s1, 1000);

    cin.getline(s2, 1000);

    int result = my_strcmp(s1, s2);
    cout << result << endl;

    return 0;
}
