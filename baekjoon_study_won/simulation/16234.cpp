#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n, l, r;
int a[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[51][51];
int res;
bool isInside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
void bfs()
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;

    while (1)
    {
        bool flag = false;
        fill(&visited[0][0], &visited[n - 1][n], 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j])
                    continue;

                q.push({j, i});
                int sum = a[i][j];
                visited[i][j] = true;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    v.push_back({x, y});
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (isInside(nx, ny) && !visited[ny][nx])
                        {
                            if (abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r)
                            {
                                visited[ny][nx] = true;
                                sum += a[ny][nx];
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                if (v.size() > 1)
                {
                    flag = true;
                    for (int i = 0; i < v.size(); i++)
                    {
                        int x = v[i].first;
                        int y = v[i].second;

                        a[y][x] = sum / v.size();
                    }
                }
                v.clear();
            }
        }

        if (flag == false)
            break;
        else
            ++res;
    }
}
int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    bfs();
    cout << res;

    return 0;
}