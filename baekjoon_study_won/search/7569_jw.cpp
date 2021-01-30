#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
bool visited[100][100][100];
int a[100][100][100];
int m, n, h;
int rst;
queue<pair<pair<int, int>, int>> q; //x y z
bool isInside(int x, int y, int z)
{
    return x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < h;
}
void bfs()
{
    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cz = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];

            if (isInside(nx, ny, nz) && !visited[nz][ny][nx] && a[nz][ny][nx] == 0)
            {
                a[nz][ny][nx] = a[cz][cy][cx] + 1;
                visited[nz][ny][nx] = true;
                q.push({{nx, ny}, nz});
            }
        }
    }

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[k][i][j] == 0)
                {
                    rst = -1;
                    return;
                }
                else
                {
                    rst = rst < a[k][i][j] - 1 ? a[k][i][j] - 1 : rst;
                }
            }
        }
    }
    return;
}
int main()
{
    bool flag = false;
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[k][i][j];
                if (a[k][i][j] == 1)
                {
                    visited[k][i][j] = true;
                    q.push({{j, i}, k});
                }
                if (a[k][i][j] == 0)
                {
                    flag = true;
                }
            }
        }
    }
    if (flag) bfs();
    cout << rst;
}