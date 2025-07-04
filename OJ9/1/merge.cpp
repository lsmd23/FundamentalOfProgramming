#include <iostream>

using namespace std;

void merge(int *a, int *b, int m, int n, int *result)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            result[k] = a[i];
            k++;
            i++;
        }
        else
        {
            result[k] = b[j];
            k++;
            j++;
        }
    }
    if (i == m)
    {
        for (int l = j; l < n; l++)
        {
            result[k] = b[l];
            k++;
        }
    }
    else
    {
        for (int l = i; l < m; l++)
        {
            result[k] = a[l];
            k++;
        }
    }
    return;
}

int main()
{
    int m;
    cin >> m;
    int a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    int n;
    cin >> n;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int result[m + n];
    merge(a, b, m, n, result);

    for (int i = 0; i < m + n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}