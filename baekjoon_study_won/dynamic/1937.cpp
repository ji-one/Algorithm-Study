#include <iostream>
#include <algorithm>
using namespace std;
int a[500][500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int d[500][500];
int n, k;
// solution
bool isInside(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}

int dfs(int x, int y)
{
    if (d[y][x] == 0)
    {
        d[y][x] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInside(nx, ny) && a[ny][nx] > a[y][x])
            {
                d[y][x] = max(d[y][x], dfs(nx, ny) + 1);
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
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int day = dfs(j, i);
            k = day > k ? day : k;
        }
    }
    cout << k;
}