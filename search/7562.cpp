#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool visited[300][300];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int l, x1, y1, x2, y2;
bool isInside(int x, int y)
{
    return x >= 0 && y >= 0 && x < l && y < l;
}
int bfs(int x, int y)
{
    fill(&visited[0][0], &visited[299][300], false);
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    visited[y][x] = true;
    while (!q.empty())
    {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cn = q.front().second;
        q.pop();

        if (cx == x2 && cy == y2)
        {
            return cn;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (isInside(nx, ny) && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({{nx, ny}, cn + 1});
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> l >> y1 >> x1 >> y2 >> x2;
        cout << bfs(x1, y1) << '\n';
    }
}