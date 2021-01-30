#include <iostream>
using namespace std;
int a[50][50];
int n, m, r, c, d;
int rst = 1;
// 1 : 벽 2 : 청소 끝
int solve(int x, int y, int dir)
{
    int ndir, nx, ny;
    if (dir == 0)
    {
        ndir = 3;
        nx = x - 1;
        ny = y;
    }
    if (dir == 1)
    {
        ndir = 0;
        nx = x;
        ny = y - 1;
    }
    if (dir == 2)
    {
        ndir = 1;
        nx = x + 1;
        ny = y;
    }
    if (dir == 3)
    {
        ndir = 2;
        nx = x;
        ny = y + 1;
    }

    if (a[y][x - 1] && a[y][x + 1] && a[y - 1][x] && a[y + 1][x]) // 청소할 곳 음슴
    {
        if (dir == 0 && a[y + 1][x] != 1) // 뒤가 벽이 아니면 후진
        {
            solve(x, y + 1, dir);
        }
        else if (dir == 1 && a[y][x - 1] != 1)
        {
            solve(x - 1, y, dir);
        }
        else if (dir == 2 && a[y - 1][x] != 1)
        {
            solve(x, y - 1, dir);
        }
        else if (dir == 3 && a[y][x + 1] != 1)
        {
            solve(x + 1, y, dir);
        }
        else
            return 0;
    }
    else if (!a[ny][nx])
    {
        ++rst;
        a[ny][nx] = 2;
        solve(nx, ny, ndir);
    }
    else
    {
        solve(x, y, ndir);
    }

    return 0;
}

int main()
{
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    a[r][c] = 2;
    solve(c, r, d);

    cout << rst;

    return 0;
}