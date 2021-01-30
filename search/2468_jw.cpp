#include <iostream>
#include <algorithm>
using namespace std;
int a[100][100];
int tmp[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, max_h, rst;
bool isInside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
void dfs(int x, int y)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isInside(nx, ny) && !visited[ny][nx] && tmp[ny][nx] == 0)
        {
            dfs(nx, ny);
        }
    }
}
void sink(int h)
{
    fill(&tmp[0][0], &tmp[99][100], 0);
    fill(&visited[0][0], &visited[99][100], false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] <= h)
            {
                tmp[i][j] = 1; // 잠김
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && tmp[i][j] == 0)
            {
                dfs(j, i);
                ++cnt;
            }
        }
    }
    rst = max(rst, cnt);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            max_h = max(max_h, a[i][j]);
        }
    }
    for (int i = 0; i <= max_h; i++)
    {
        sink(i);
    }

    cout << rst;
}