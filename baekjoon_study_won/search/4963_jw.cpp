#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int a[50][50];
bool visited[50][50];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int w, h;
bool isInside(int x, int y)
{
    return x >= 0 && x < w && y >= 0 && y < h;
}
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (isInside(nx, ny) && !visited[ny][nx] && a[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> a[i][j];
            }
        }
        int rst = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!visited[i][j] && a[i][j] == 1)
                {
                    bfs(j, i);
                    ++rst;
                }
            }
        }
        cout << rst << '\n';
        fill(&visited[0][0], &visited[49][50], false);
    }
    return 0;
}