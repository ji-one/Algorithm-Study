#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
int a[101][101];
int t;
int dx[4] = {1, 0, -1, 0}; // 오 하 왼 상
int dy[4] = {0, 1, 0, -1};
queue<pair<int, char>> dir;
deque<pair<int, int>> dq;
int n, k, l;
int isInside(int x, int y)
{
    return x >= 1 && y >= 1 && x <= n && y <= n;
}
void game(int x, int y, int d)
{
    ++t;
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (isInside(nx, ny))
    {
        if (a[ny][nx] == 1)
            return;
        if (a[ny][nx] == 2) // 사과 o
        {
            a[ny][nx] = 1;
            dq.push_front({nx, ny});
        }
        if (a[ny][nx] == 0) // 사과 x
        {
            int tx = dq.back().first;
            int ty = dq.back().second; // tail
            a[ty][tx] = 0;
            dq.pop_back();

            a[ny][nx] = 1;
            dq.push_front({nx, ny});
        }

        if (t == dir.front().first)
        {
            if (dir.front().second == 'L')
                d = (d + 3) % 4;
        
            if (dir.front().second == 'D')
                d = (d + 1) % 4;
            
            dir.pop();
        }
        game(nx, ny, d);
    }
    else
    {
        return;
    }
}
int main()
{
    cin >> n >> k;
    while (k--)
    {
        int r, c;
        cin >> r >> c;
        a[r][c] = 2; // 사과
    }
    cin >> l;
    while (l--)
    {
        int x;
        char d;
        cin >> x >> d;
        dir.push({x, d});
    }

    dq.push_front({1, 1});
    game(1, 1, 0);
    cout << t;
    return 0;
}