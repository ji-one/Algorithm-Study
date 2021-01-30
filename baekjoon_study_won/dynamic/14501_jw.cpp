#include <iostream>
#include <algorithm>
using namespace std;
// solution 봄
int t[16];
int p[16];
int d[16];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
        d[i] = p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (j + t[j] <= i)
            {
                d[i] = max(d[i], d[j] + p[i]);
            }
        }
    }
    int rst = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i + t[i] <= n + 1)
            rst = max(rst, d[i]);
    }
    cout << rst;
    return 0;
}
