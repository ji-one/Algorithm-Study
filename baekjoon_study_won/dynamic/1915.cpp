#include <iostream>
#include <algorithm>
using namespace std;
// solution
int a[1001][1001];
int res;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &a[i][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != 0)
            {
                a[i][j] = min(a[i - 1][j - 1], min(a[i - 1][j], a[i][j - 1])) + 1;
                res = max(res, a[i][j]);
            }
        }
    }
    cout << res * res << '\n';
    return 0;
}
