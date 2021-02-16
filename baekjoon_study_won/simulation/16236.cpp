#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int a[20][20];
int visited[20][20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int rst = 0;
int sz = 2;
int n;
bool flag;
vector<pair<int, pair<int, int>>> v;
int compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.first == b.first)
    {
        // 가깝고-> 위쪽 ->왼쪽
        if (a.second.second == b.second.second)
        {
            return a.second.first < b.second.first;
        }
        return a.second.second < b.second.second;
    }
    return a.first < b.first;
}
bool isInside(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}
void bfs(int x, int y)
{
    fill(&visited[0][0], &visited[n - 1][n], 0);
    flag = false;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        if (a[cy][cx] && a[cy][cx] < sz) // 물고기 먹을 수 있는 경우
        {
            v.push_back({visited[cy][cx], {cx, cy}});
            flag = true;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (isInside(nx, ny) && !visited[ny][nx] && a[ny][nx] <= sz)
                {
                    q.push({nx, ny});
                    visited[ny][nx] = visited[cy][cx] + 1;
                }
            }
        }
    }
}
int main()
{
    int x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 9)
            {
                x = j;
                y = i;
                a[i][j] = 0;
            }
        }
    }
    int cnt = 0;
    while (1)
    {
        bfs(x, y);
        if (flag == false)
            break;

        sort(v.begin(), v.end(), compare);
        rst += v[0].first;
        x = v[0].second.first;
        y = v[0].second.second;
        a[y][x] = 0;
        v.clear();
        ++cnt;
        if (cnt == sz)
        {
            ++sz;
            cnt = 0;
        }
    }
    cout << rst;
}