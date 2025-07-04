#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int temp_elem = array[0], num = 0;
    int mode_elem = array[0], mode_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] != temp_elem)
        {
            int count = i - num;
            if (count > mode_count)
            {
                mode_elem = array[i - 1];
                mode_count = count;
            }

            num = i;
            temp_elem = array[i];
        }
        if (i == n - 1)
        {
            int count = i - num + 1;
            if (count > mode_count)
            {
                mode_elem = array[i];
            }
        }
    }

    cout << mode_elem << endl;

    return 0;
}