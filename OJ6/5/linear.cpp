#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int size;
    cin >> size;

    double matrix[size][size + 1];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    } // 输入矩阵

    for (int i = 0; i < size; i++)
    {
        cin >> matrix[i][size];
    }
    // 输入向量为矩阵最后一列

    for (int j = 0; j < size; j++)
    {
        bool isZero = true;
        for (int i = 0; i < size; i++)
        {
            if (matrix[i][j] != 0)
            {
                isZero = false;
                break;
            }
        }
        if (isZero)
        {
            cout << "Error" << endl;
            return 0;
        }
    }
    // 寻找系数矩阵有无全为0的列，若有全0列，则不是唯一解，输出错误

    for (int i = 0; i < size; i++)
    {
        if (matrix[i][i] == 0)
        {
            bool isColumnZero = true;
            for (int i2 = i + 1; i2 < size; i2++)
            {
                if (matrix[i2][i] != 0)
                {
                    isColumnZero = false;
                    double temp[size + 1];
                    for (int temp_i = 0; temp_i < size + 1; temp_i++)
                    {
                        temp[temp_i] = matrix[i2][temp_i];
                        matrix[i2][temp_i] = matrix[i][temp_i];
                        matrix[i][temp_i] = temp[temp_i];
                    }
                }
            } // 若首元素为0，则向下寻找有无非零的行，对换

            if (isColumnZero)
            {
                cout << "Error" << endl;
                return 0;
            } // 若全为零的列，则一定不是唯一解
        }

        for (int i2 = i + 1; i2 < size; i2++)
        {
            double times = matrix[i2][i] / matrix[i][i];
            for (int j = i; j < size + 1; j++)
            {
                matrix[i2][j] = matrix[i2][j] - matrix[i][j] * times;
            }
        }
    }
    // 从第一行开始，消元，遍历下面的行，消去第一列其他元素为0，之后重复，化为上三角矩阵

    for (int i = 0; i < size; i++)
    {
        bool isZero = true;
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != 0)
            {
                isZero = false;
                break;
            }
        }
        if (isZero)
        {
            cout << "Error" << endl;
            return 0;
        }
    }
    // 寻找系数矩阵有无全为0的行，若有全0行，则不是唯一解，输出错误

    for (int i = size - 1; i > 0; i--)
    {
        for (int i2 = i - 1; i2 >= 0; i2--)
        {
            double times = matrix[i2][i] / matrix[i][i];
            matrix[i2][i] = 0;
            matrix[i2][size] = matrix[i2][size] - times * matrix[i][size];
        }
    }
    // 从下向上消元，消元至对角矩阵

    for (int i = 0; i < size; i++)
    {
        matrix[i][size] *= 1 / matrix[i][i];
        matrix[i][i] = 1;
    }
    // 倍乘，系数矩阵化为单位阵

    for (int i = 0; i < size; i++)
    {
        cout << fixed << setprecision(2) << matrix[i][size] << endl;
    }
    // 输出向量为解

    //   for (int i = 0; i < size; i++)
    //   {
    //       for (int j = 0; j < size; j++)
    //           cout << matrix[i][j];
    //       cout << endl;
    //   }

    return 0;
}