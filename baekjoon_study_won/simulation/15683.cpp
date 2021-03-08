#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// solution
int n, m;
int map[9][9];
int tmp[9][9];
struct info
{
    int x, y, type, dir;
};
vector<info> cctv;
int res = 100;
void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp[i][j] = map[i][j];
}
void right(int x, int y)
{
    for (int i = x; i < m; i++)
    {
        if (tmp[y][i] == 6)
            break;
        if (tmp[y][i] == 0)
            tmp[y][i] = -1;
    }
}

void left(int x, int y)
{
    for (int i = x; i >= 0; i--)
    {
        if (tmp[y][i] == 6)
            break;
        if (tmp[y][i] == 0)
            tmp[y][i] = -1;
    }
}

void down(int x, int y)
{
    for (int i = y; i >= 0; i--)
    {
        if (tmp[i][x] == 6)
            break;
        if (tmp[i][x] == 0)
            tmp[i][x] = -1;
    }
}

void up(int x, int y)
{
    for (int i = y; i < n; i++)
    {
        if (tmp[i][x] == 6)
            break;
        if (tmp[i][x] == 0)
            tmp[i][x] = -1;
    }
}
void check(vector<info> &v)
{
    init();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].type == 1)
        {
            if (v[i].dir == 0)
                right(v[i].x, v[i].y);
            if (v[i].dir == 1)
                left(v[i].x, v[i].y);
            if (v[i].dir == 2)
                down(v[i].x, v[i].y);
            if (v[i].dir == 3)
                up(v[i].x, v[i].y);
        }
        if (v[i].type == 2)
        {
            if (v[i].dir == 0 || v[i].dir == 2)
            {
                right(v[i].x, v[i].y);
                left(v[i].x, v[i].y);
            }
            if (v[i].dir == 1 || v[i].dir == 3)
            {
                down(v[i].x, v[i].y);
                up(v[i].x, v[i].y);
            }
        }
        if (v[i].type == 3)
        {
            if (v[i].dir == 0)
            {
                right(v[i].x, v[i].y);
                up(v[i].x, v[i].y);
            }
            if (v[i].dir == 1)
            {
                left(v[i].x, v[i].y);
                down(v[i].x, v[i].y);
            }
            if (v[i].dir == 2)
            {
                right(v[i].x, v[i].y);
                down(v[i].x, v[i].y);
            }
            if (v[i].dir == 3)
            {
                left(v[i].x, v[i].y);
                up(v[i].x, v[i].y);
            }
        }
        if (v[i].type == 4)
        {
            if (v[i].dir == 0) // ㅗ
            {
                left(v[i].x, v[i].y);
                right(v[i].x, v[i].y);
                up(v[i].x, v[i].y);
            }
            if (v[i].dir == 1) // ㅜ
            {
                right(v[i].x, v[i].y);
                left(v[i].x, v[i].y);
                down(v[i].x, v[i].y);
            }
            if (v[i].dir == 2) // ㅏ
            {
                up(v[i].x, v[i].y);
                right(v[i].x, v[i].y);
                down(v[i].x, v[i].y);
            }
            if (v[i].dir == 3) // ㅓ
            {
                up(v[i].x, v[i].y);
                down(v[i].x, v[i].y);
                left(v[i].x, v[i].y);
            }
        }
        if (v[i].type == 5)
        {
            right(v[i].x, v[i].y);
            left(v[i].x, v[i].y);
            down(v[i].x, v[i].y);
            up(v[i].x, v[i].y);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp[i][j] == 0)
                ++cnt;
        }
    }
    res = min(res, cnt);
}
void dfs(int cnt, vector<info> &v)
{
    if (cnt == v.size())
    {
        check(v);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        v[cnt].dir = i;
        dfs(cnt + 1, v);
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
            if (map[i][j] != 0 && map[i][j] != 6)
                cctv.push_back({j, i, map[i][j], 0});
        }
    }
    dfs(0, cctv);
    cout << res;
    return 0;
}