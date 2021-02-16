#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
int main()
{
    int n, m, g, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> g >> x;
        if (g == 1) // 남
        {
            for (int j = 1; j <= n; j++)
            {
                if (j % x == 0)
                {
                    a[j] = !a[j];
                }
            }
        }
        if (g == 2) // 여
        {
            a[x] = !a[x];
            for (int d = 1; x + d <= n && x - d >= 1; d++)
            {
                if (a[x + d] == a[x - d])
                {
                    a[x + d] = !a[x + d];
                    a[x - d] = !a[x - d];
                }
                else
                    break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
    return 0;
}