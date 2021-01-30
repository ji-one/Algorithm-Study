#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// ? 답봄
int a[50][50];
int b[50][50];
void reverse(int x, int y)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[y + i][x + j] = !a[y + i][x + j];
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &a[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &b[i][j]);

    int res = 0;

    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = 0; j <= m - 3; j++)
        {
            if (a[i][j] != b[i][j])
            {
                reverse(j, i);
                ++res;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                cout << "-1";
                return 0;
            }
        }
    }
    cout << res;
    return 0;
}