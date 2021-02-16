#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int r, c;
char map[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int visited[51][51];
queue<pair<int, int>> v; // water
bool isInside(int x, int y)
{
    return x >= 0 && y >= 0 && x < c && y < r;
}
void water()
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        int cx = v.front().first;
        int cy = v.front().second;
        v.pop();
        for (int j = 0; j < 4; j++)
        {
            int nx = cx + dx[j];
            int ny = cy + dy[j];

            if (isInside(nx, ny) && map[ny][nx] == '.')
            {
                map[ny][nx] = '*';
                v.push({nx, ny});
            }
        }
    }
}
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = 1;
    while (!q.empty())
    {
        water();

        for (int k = 0; k < q.size(); k++)
        {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            if (map[cy][cx] == 'D')
            {
                cout << visited[cy][cx] - 1;
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (isInside(nx, ny) && !visited[ny][nx])
                {
                    if (map[ny][nx] != '*' && map[ny][nx] != 'X')
                    {
                        q.push({nx, ny});
                        visited[ny][nx] = visited[cy][cx] + 1;
                    }
                }
            }
        }
    }
    cout << "KAKTUS";
    return;
}
int main()
{
    int x, y;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                x = j;
                y = i;
            }
            if (map[i][j] == '*')
                v.push({j, i});
        }
    }

    bfs(x, y);
    return 0;
}