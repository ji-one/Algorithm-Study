#include <iostream>
#include<algorithm>
using namespace std;
int a[500][500];
bool visited[500][500];
int n, m, max_sum, rst;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool isInside(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}
void dfs(int x, int y, int cnt, int sum)
{
    if (cnt == 4)
    {
        max_sum = max_sum < sum ? sum : max_sum;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isInside(nx, ny) && !visited[ny][nx])
        {
            visited[ny][nx] = true;
            dfs(nx, ny, cnt + 1, sum + a[ny][nx]);
            visited[ny][nx] = false;
        }
    }
}
int middleFinger(int x, int y)
{
    int rst = 0;
    if (y >= 1 && x >= 1 && x < m - 1) // ㅗ
        rst = max(rst, a[y][x - 1] + a[y][x] + a[y][x + 1] + a[y - 1][x]);
    if (y >= 1 && y < n - 1 && x < m - 1) // ㅏ
        rst = max(rst, a[y - 1][x] + a[y][x] + a[y + 1][x] + a[y][x + 1]);
    if (x >= 1 && y < n - 1 && x < m - 1) // ㅜ
        rst = max(rst, a[y][x - 1] + a[y][x] + a[y][x + 1] + a[y + 1][x]);
    if (x >= 1 && y < n - 1 && y >= 1) // ㅓ
        rst = max(rst, a[y - 1][x] + a[y][x] + a[y + 1][x] + a[y][x - 1]);

    return rst;
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            dfs(j, i, 1, a[i][j]);
            rst = max(rst, max_sum);
            rst = max(rst, middleFinger(j, i));
            max_sum = 0;
            visited[i][j] = false;
        }
    }

    cout << rst;

    return 0;
}
