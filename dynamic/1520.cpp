#include <iostream>
#include <algorithm>
using namespace std;
// solution 봄
int m, n, cnt;
int a[500][500];
int d[500][500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int isInside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
int dfs(int x, int y)
{
    if (x == n - 1 && y == m - 1)
        return 1;

    if (d[y][x] == -1)
    {
        d[y][x] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isInside(nx, ny) && a[y][x] > a[ny][nx])
            {
                d[y][x] += dfs(nx, ny);
            }
        }
    }

    return d[y][x];
}
int main()
{
    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            d[i][j] = -1;
        }

    cout << dfs(0, 0);
    // for(int i=0; i<m; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         cout<<d[i][j];
    //     }
    //     cout<<'\n';
    // }
}