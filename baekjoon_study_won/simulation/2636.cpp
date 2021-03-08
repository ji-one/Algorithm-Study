#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int a[101][101];
int visited[101][101];
bool melted[101][101];
int n, m;
int cheese;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> v;
queue<pair<int, int>> tmp;
bool isInside(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}
void melting(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isInside(nx, ny) && a[ny][nx] == 1 && !melted[ny][nx])
        {
            --cheese;
            melted[ny][nx] = true;
            tmp.push({nx, ny});
        }
    }
}
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({x, y});
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        melting(cx, cy);
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (isInside(nx, ny) && !visited[ny][nx] && a[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                q.push({nx, ny});
            }
        }
    }

    while (!tmp.empty())
    {
        int cx = tmp.front().first;
        int cy = tmp.front().second;
        tmp.pop();

        a[cy][cx] = 0;
    }

    v.push_back(cheese);
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                ++cheese;
        }
    }
    int res = 0;
    v.push_back(cheese);
    while (cheese)
    {
        fill(&visited[0][0], &visited[100][101], 0);
        bfs(0, 0);
        ++res;
    }
    cout << res << '\n'
         << v[v.size() - 2];

    return 0;
}