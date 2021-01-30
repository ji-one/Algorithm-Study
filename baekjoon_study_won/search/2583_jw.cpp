#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, k;
int a[100][100];
bool visited[100][100];
vector<int> rst;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool isInside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (isInside(nx, ny) && !visited[ny][nx] && !a[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
        ++cnt;
    }
    rst.push_back(cnt);
}
int main()
{
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++)
        {
            for (int l = x1; l < x2; l++)
            {
                a[j][l] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0 && !visited[i][j])
            {
                bfs(j, i);
                ++cnt;
            }
        }
    }
    sort(rst.begin(), rst.end());
    cout << rst.size() << '\n';
    for (int i = 0; i < rst.size(); i++)
    {
        cout << rst[i] << ' ';
    }
}