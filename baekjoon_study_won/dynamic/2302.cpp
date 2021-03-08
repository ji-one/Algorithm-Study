#include <iostream>
#include <algorithm>
using namespace std;
int d[40];
int main()
{
    int n, m;
    cin >> n >> m;
    int cur = 0;
    int res = 1;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++)
        d[i] = d[i - 1] + d[i - 2];

    for (int i = 0; i < m; i++)
    {
        int vip;
        cin >> vip;
        int num = vip - cur - 1;
        if (num != 0)
            res *= d[num];
        cur = vip;
    }
    if (cur != n)
        res *= d[n - cur];

    cout << res;
    return 0;
}