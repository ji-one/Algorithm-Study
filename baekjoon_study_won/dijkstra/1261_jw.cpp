#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
// BFS로는 Q에 들어가는 원소가 너무 많아질 수밖에 없음
int a[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int d[100][100];
int m, n;
bool isInside(int x, int y)
{
    return x >= 0 && y >= 0 && x < m && y < n;
}
void dijkstra(int x, int y)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    d[y][x] = 0;
    pq.push({0, {x, y}});
    while (!pq.empty())
    {
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        int cc = -pq.top().first;

        pq.pop();

        if (cc > d[cy][cx])
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (isInside(nx, ny))
            {
                if (a[ny][nx] == 1 && cc + 1 < d[ny][nx])
                {
                    d[ny][nx] = cc + 1;
                    pq.push({-(cc + 1), {nx, ny}});
                }
                if (a[ny][nx] == 0 && cc < d[ny][nx])
                {
                    d[ny][nx] = cc;
                    pq.push({-cc, {nx, ny}});
                }
            }
        }
    }
}
int main()
{
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
            d[i][j] = INT_MAX;
        }
    }

    dijkstra(0, 0);

    cout << d[n - 1][m - 1];

    return 0;
}