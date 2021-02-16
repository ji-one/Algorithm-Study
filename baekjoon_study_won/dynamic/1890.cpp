#include <iostream>
#include <algorithm>
using namespace std;
int a[100][100];
long long d[100][100];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int n;
bool isInside(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}
long long dfs(int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        return 1;
    }

    if (d[y][x] == -1)
    {
        d[y][x] = 0;

        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i] * a[y][x];
            int ny = y + dy[i] * a[y][x];

            if (isInside(nx, ny))
            {
                d[y][x] += dfs(nx, ny);
            }
        }
    }
    return d[y][x];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            d[i][j] = -1;
        }
    }
    cout << dfs(0, 0);
}