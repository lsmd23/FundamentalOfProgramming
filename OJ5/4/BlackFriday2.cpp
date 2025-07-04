// #include <iostream>
// #include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int MonthDayNumber(int year, int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

bool isFriday(int year, int month, int day)
{
    int pastDays = 0;

    // 累加day之前的天数
    for (; day > 1; day--)
    {
        pastDays++;
    }

    // 累加year年1月到month前一个月的天数
    for (; month > 1; month--)
    {
        pastDays += MonthDayNumber(year, month - 1);
    }

    // 累加从1998年到year的天数
    for (; year > 1998; year--)
    {
        pastDays += isLeapYear(year - 1) ? 366 : 365;
    }

    return (pastDays % 7 == 1); // 修改偏移量为5表示星期五
}

int main()
{
    int year;
    cin >> year;

    for (int month = 1; month <= 12; month++)
    {
        if (isFriday(year, month, 13))
        {
            printf("%04d-%02d-%02d\n", year, month, 13);
        }
    }

    return 0;
}
