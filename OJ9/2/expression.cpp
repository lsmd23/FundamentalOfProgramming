#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int expression(char *s)
{
    int res = 0;
    int temp_num[500];
    bool temp_op[500];
    string num;
    int i = 0, j = 0;
    for (; s[i] != '\0'; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '=')
        {
            temp_num[j] = stoi(num);
            if (s[i] == '+')
            {
                temp_op[j] = 1;
            }
            else if (s[i] == '-')
            {
                temp_op[j] = 0;
            }
            else
            {
                break;
            }
            j++;
            num = "";
        }
        else
        {
            num += s[i];
        }
    }
    res = temp_num[0];
    for (int k = 0; k < j; k++)
    {
        if (temp_op[k] == 1)
        {
            res += temp_num[k + 1];
        }
        else
        {
            res -= temp_num[k + 1];
        }
    }
    return res;
}

int main()
{
    char s[1000];
    scanf("%s", s);
    printf("%d", expression(s));
    return 0;
}