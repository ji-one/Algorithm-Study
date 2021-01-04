#include <iostream>
#include <string>
#include <queue>
using namespace std;
int map[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int rst = 0;
int n, m;
int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (map[nx][ny] == 1 && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    map[nx][ny] = map[cx][cy] + 1;
                }
            }
        }
        q.pop();
    }

    return map[n - 1][m - 1];
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    cout << bfs(0, 0);

    return 0;
}