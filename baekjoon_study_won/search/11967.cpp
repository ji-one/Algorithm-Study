#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// solution
// 방문했을 때 불이 꺼져있으면 일단 tmp에 push
// 불 켜져있는 곳이면 이동 후 다 불켜기
vector<pair<int, int>> swt[101][101];
int map[101][101]; // 불 켜져있는지 확인
int n, m, res = 1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[101][101];
int tmp[101][101]; // 임시 방문
int isInside(int x, int y)
{
    return x >= 1 && y >= 1 && x <= n && y <= n;
}

void turnOn()
{
    queue<pair<int, int>> q; // 불 켜져있는 방
    q.push({1, 1});
    visited[1][1] = 1;
    map[1][1] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < swt[y][x].size(); i++)
        {
            int a = swt[y][x][i].first;
            int b = swt[y][x][i].second;
            if (map[b][a] != 1)
            {
                res++;
                map[b][a] = 1; // 불켜줌
            }

            if (!visited[b][a] && tmp[b][a]) // 임시 방문 했던 위치 (???)
            {
                q.push({a, b});
                visited[b][a] = 1;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInside(nx, ny) && !visited[ny][nx])
            {
                if (!map[ny][nx]) // 불 안켜져있으면
                {
                    tmp[ny][nx] = 1;
                } 
                else // 불 켜져있으면 이동 가능
                {
                    visited[ny][nx] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        swt[y][x].push_back({a, b});
    }
    turnOn();
    cout << res;
    return 0;
}