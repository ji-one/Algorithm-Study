#include <iostream>
#include <string>
#include <queue>
using namespace std;
string s[100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool visited[100][100];
int n;
int a, b;
bool isInside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
void dfs(char c, int x, int y)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isInside(nx, ny) && !visited[ny][nx] && s[ny][nx] == c)
        {
            dfs(c, nx, ny);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                dfs(s[i][j], j, i);
                ++a;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == 'R')
            {
                s[i][j] = 'G';
            }
        }
    }
    fill(&visited[0][0], &visited[99][100], false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                dfs(s[i][j], j, i);
                ++b;
            }
        }
    }
    cout << a << ' ' << b;
    return 0;
}