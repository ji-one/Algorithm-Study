#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int m, n, k;
int a[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool isInside(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isInside(nx, ny) && a[ny][nx])
        {
            a[ny][nx] = 0;
            dfs(nx, ny);
        }
    }
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        fill(&a[0][0], &a[50][51], 0);
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            a[y][x] = 1;
        }

        int rst = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j])
                {
                    a[i][j] = 0;
                    dfs(j, i);
                    ++rst;
                }
            }
        }
        cout << rst << '\n';
    }
}