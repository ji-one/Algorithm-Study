#include <iostream>
#include <algorithm>
using namespace std;
string s[20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited['Z' + 1];
int r, c;
int rst = 0;
bool isInside(int x, int y)
{
    return x >= 0 && y >= 0 && x < c && y < r;
}
void dfs(int x, int y, int cnt)
{
    if (cnt > rst)
    {
        rst = cnt;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isInside(nx, ny) && !visited[s[ny][nx]])
        {
            visited[s[ny][nx]] = true;
            dfs(nx, ny, cnt + 1);
            visited[s[ny][nx]] = false;
        }
    }
}
int main()
{
    cin >> r >> c;

    for (int i = 0; i <= r; i++)
    {
        cin >> s[i];
    }
    visited[s[0][0]] = 1;
    dfs(0, 0, 1);
    cout << rst;
    return 0;
}