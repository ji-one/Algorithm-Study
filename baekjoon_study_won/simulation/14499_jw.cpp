#include <iostream>
using namespace std;
int map[20][20];
int n, m, x, y, k;
int dice[6];
int dx[4] = {0, 0, -1, 1}; // 동 서 북 남
int dy[4] = {1, -1, 0, 0};
// 주사위 바닥 지도가 0이면 주사위 바닥 수가 지도에 복사
// 0이 아니면 지도의 수가 주사위에 복사
bool isInside(int r, int c)
{
    return (r >= 0 && c >= 0 && r < n && c < m);
}
void solve(int dir)
{
    int nx = x + dx[dir - 1];
    int ny = y + dy[dir - 1];
    
    if (!isInside(nx, ny))
        return;
    else
    {
        x = nx;
        y = ny;
    }

    // 동쪽
    if (dir == 1)
    {
        int tmp = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = dice[0];
        dice[0] = tmp;
    }
    // 서쪽
    if (dir == 2)
    {
        int tmp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = tmp;
    }
    // 북쪽
    if (dir == 3)
    {
        int tmp = dice[1];
        dice[1] = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = tmp;
    }
    // 남쪽
    if (dir == 4)
    {
        int tmp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = tmp;
    }

    if (!map[x][y])
    {
        map[x][y] = dice[5];
    }
    else
    {
        dice[5] = map[x][y];
        map[x][y] = 0;
    }
    cout << dice[0] << '\n'; //윗면
}
int main()
{
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    // x가 r, y가 c
    while (k--)
    {
        int d;
        cin >> d;
        solve(d);
    }
    return 0;
}