#include <stdio.h>
#include <string.h>
#include <ctype.h>

void multiply(char *s1, char *s2, char *result, int result_size)
{
    int i, j, k, len1, len2, len;
    int carry, temp;

    // 检查输入字符串是否为有效数字
    for (i = 0; s1[i] != '\0'; i++)
    {
        if (!isdigit(s1[i]))
        {
            printf("Invalid input: s1 contains non-digit characters.\n");
            return;
        }
    }
    for (i = 0; s2[i] != '\0'; i++)
    {
        if (!isdigit(s2[i]))
        {
            printf("Invalid input: s2 contains non-digit characters.\n");
            return;
        }
    }

    len1 = strlen(s1);
    len2 = strlen(s2);
    len = len1 + len2;

    // 检查结果数组是否足够大
    if (result_size < len + 1)
    {
        printf("Result array is too small.\n");
        return;
    }

    for (i = 0; i < len; i++)
        result[i] = '0';
    result[len] = '\0';

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            temp = (s1[i] - '0') * (s2[j] - '0') + (result[i + j + 1] - '0') + carry; // result[i+j+1] is the current digit
            carry = temp / 10;
            result[i + j + 1] = temp % 10 + '0';
        }
        result[i + j + 1] = carry + '0';
    }

    for (i = 0; i < len; i++)
    {
        if (result[i] != '0')
            break;
    } // find the first non-zero digit

    if (i == len)
    {
        result[0] = '0';
        result[1] = '\0';
    } // if all digits are zero
    else
    {
        for (j = 0; i < len; i++, j++)
            result[j] = result[i];
        result[j] = '\0';
    } // copy the result to the beginning of the array
}

int main()
{
    char s1[20], s2[20], result[40];

    scanf("%s", s1);
    scanf("%s", s2);

    multiply(s1, s2, result, sizeof(result));
    printf("%s\n", result);

    return 0;
}