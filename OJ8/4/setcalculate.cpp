#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

vector<int> intersection(const vector<int> &A, const vector<int> &B)
{
    vector<int> result;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
    return result;
}

vector<int> union_set(const vector<int> &A, const vector<int> &B)
{
    vector<int> result;
    set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
    return result;
}

vector<int> difference(const vector<int> &A, const vector<int> &B)
{
    vector<int> result;
    set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
    return result;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> B[i];
    }

    vector<int> inter = intersection(A, B);
    vector<int> uni = union_set(A, B);
    vector<int> diff = difference(A, B);

    for (int i : inter)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i : uni)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i : diff)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}