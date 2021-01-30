#include <iostream>
using namespace std;
int a[501][501];
int d[501][501];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }

    d[0][0] = a[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j != 0)
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
            else
                d[i][j] = d[i - 1][j] + a[i][j];
        }
    }
    int rst = 0;
    for (int i = 0; i < n; i++)
    {
        rst = rst < d[n - 1][i] ? d[n - 1][i] : rst;
    }
    cout << rst;
    return 0;
}