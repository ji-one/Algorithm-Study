#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, t;
int a[51][51];
vector<pair<int, int>> air;
vector<pair<int, int>> dust;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int tmp[51][51];
bool isInside(int x, int y)
{
    return x >= 0 && y >= 0 && x < c && y < r;
}
void spread()
{
    fill(&tmp[0][0], &tmp[r - 1][c], 0);
    int n = dust.size();
    int cx, cy, cq, nx, ny, cnt;
    for (int i = 0; i < n; i++)
    {
        cx = dust[i].first;
        cy = dust[i].second;
        cq = a[cy][cx] / 5;
        cnt = 0; // 확산 개수
        if (cq != 0)
        {
            for (int i = 0; i < 4; i++)
            {
                nx = cx + dx[i];
                ny = cy + dy[i];
                if (isInside(nx, ny) && a[ny][nx] != -1)
                {
                    if (a[ny][nx] == 0)
                        dust.push_back({nx, ny});
                    tmp[ny][nx] += cq;
                    ++cnt;
                }
            }
            a[cy][cx] -= cq * cnt;
        }
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            a[i][j] += tmp[i][j];
}
void clean()
{
    int x, y, cx, cy, nx, ny, dir, prev;
    for (int i = 0; i < 2; i++)
    {
        x = air[i].first;
        y = air[i].second;

        dir = 1; // right
        prev = a[y][x + 1];
        a[y][x + 1] = 0;
        cx = x + dx[dir];
        cy = y + dy[dir];

        while (1)
        {
            nx = cx + dx[dir];
            ny = cy + dy[dir];
            if (ny == y && nx == x)
                break;
            if (nx == c - 1 && ny == y)
            {
                if (i == 0)
                    dir = 3;
                else
                    dir = 2;
            }
            if (nx == c - 1 && ny == 0)
                dir = 0;
            if (nx == 0 && ny == 0)
                dir = 2;
            if (nx == c - 1 && ny == r - 1)
                dir = 0;
            if (nx == 0 && ny == r - 1)
                dir = 3;

            int cur = a[ny][nx];
            a[ny][nx] = prev;
            prev = cur;
            cx = nx, cy = ny;
        }
    }
}
int main()
{
    cin >> r >> c >> t;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == -1)
                air.push_back({j, i});
            else if (a[i][j] != 0)
                dust.push_back({j, i});
        }
    }

    while (t--)
    {
        spread();
        cout << "-------------\n";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        clean();
        cout << "-------------\n";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    int res = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != -1)
                res += a[i][j];
        }
    }
    cout << res;
    return 0;
}