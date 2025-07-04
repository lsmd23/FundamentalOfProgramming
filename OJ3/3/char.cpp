#include <iostream>
using namespace std;

int main()
{
    // 定义统计变量
    int spaceCount = 0;   // 空格数
    int newlineCount = 0; // 换行符数
    int otherCount = 0;   // 其他字符数

    char ch;
    while (cin.get(ch))
    {
        if (ch == '#')
        {
            break;
        }
        else if (ch == ' ')
        {
            spaceCount++;
        }
        else if (ch == '\n')
        {
            newlineCount++;
        }
        else
        {
            otherCount++;
        }
    }

    cout << spaceCount << " " << newlineCount << " " << otherCount << endl;

    return 0;
}
