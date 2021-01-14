#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int map[10][10];
bool visited[10][10];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> v;
int tmp[3];
int sz;
int a[10][10];
int rst;
bool isInside(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}
void setMap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = map[i][j];
        }
    }
}
int count()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                ++cnt;
            }
        }
    }
    return cnt;
}
void bfs(int x, int y)
{
    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (isInside(nx, ny) && a[ny][nx] == 0 && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                a[ny][nx] = 2;
                q.push({nx, ny});
            }
        }
    }
}
void choose(int idx, int cnt) // 벽 선택
{
    if (cnt == 3)
    {
        fill(&visited[0][0], &visited[9][0], false);
        setMap();
        for (int i = 0; i < 3; i++)
        {
            a[v[tmp[i]].second][v[tmp[i]].first] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 2 && !visited[i][j])
                {
                    bfs(j, i);
                }
            }
        }
        int num = count();
        rst = rst < num ? num : rst;
        return;
    }

    for (int i = idx; i < v.size(); i++)
    {
        tmp[cnt] = i;
        choose(i + 1, cnt + 1);  1~10  
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
                v.push_back({j, i});
        }
    }
    choose(0, 0);
    cout << rst;
}