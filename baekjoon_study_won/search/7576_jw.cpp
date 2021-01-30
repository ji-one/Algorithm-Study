#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n;
int a[1000][1000];
bool visited[1000][1000];
queue<pair<int, int>> q;
int isInside(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}
int bfs()
{
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (isInside(nx, ny) && !visited[ny][nx])
            {
                if (a[ny][nx] == 0)
                {
                    visited[ny][nx] = true;
                    a[ny][nx] = a[cy][cx] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int rst = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
                return -1;
            else
                rst = rst < a[i][j] ? a[i][j] : rst;
        }
    }
    return rst - 1;
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                q.push({j, i});
                visited[i][j] = true;
            }
        }
    }

    cout << bfs();
}