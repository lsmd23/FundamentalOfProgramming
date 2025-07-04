#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

void transfer(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= 'A' - 'a';
    }
}

int cmpnum(const char *word)
{
    if (strcmp(word, "zero") == 0)
        return 0;
    if (strcmp(word, "one") == 0)
        return 1;
    if (strcmp(word, "two") == 0)
        return 2;
    if (strcmp(word, "three") == 0)
        return 3;
    if (strcmp(word, "four") == 0)
        return 4;
    if (strcmp(word, "five") == 0)
        return 5;
    if (strcmp(word, "six") == 0)
        return 6;
    if (strcmp(word, "seven") == 0)
        return 7;
    if (strcmp(word, "eight") == 0)
        return 8;
    if (strcmp(word, "nine") == 0)
        return 9;
    if (strcmp(word, "ten") == 0)
        return 10;
    if (strcmp(word, "eleven") == 0)
        return 11;
    if (strcmp(word, "twelve") == 0)
        return 12;
    if (strcmp(word, "thirteen") == 0)
        return 13;
    if (strcmp(word, "fourteen") == 0)
        return 14;
    if (strcmp(word, "fifteen") == 0)
        return 15;
    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore(); // 忽略换行符

    char str[200000];
    std::cin.getline(str, sizeof(str));

    transfer(str);

    std::vector<int> numbers;

    char *token = strtok(str, " ");
    while (token != nullptr)
    {
        int num = cmpnum(token);
        if (num >= 0)
        {
            numbers.push_back((num * num) % 100);
        }
        token = strtok(nullptr, " ");
    }

    std::sort(numbers.begin(), numbers.end());

    std::string password;
    for (int num : numbers)
    {
        if (num < 10)
        {
            password += '0';
        }
        password += std::to_string(num);
    }

    // 去除前导零
    size_t pos = password.find_first_not_of('0');
    if (pos != std::string::npos)
    {
        password = password.substr(pos);
    }
    else
    {
        password = "0";
    }

    std::cout << password << std::endl;

    return 0;
}