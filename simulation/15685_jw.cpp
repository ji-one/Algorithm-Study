#include <iostream>
#include <cmath>
using namespace std;
int a[101][101];
int dir[4][1024];
void dragonCurve()
{
    for (int k = 0; k <= 3; k++)
    {
        int idx = 1;
        dir[k][0] = k;
        for (int i = 1; i <= 10; i++)
        {
            int num = pow(2, i - 1);
            for (int j = num - 1; j >= 0; j--)
            {
                dir[k][idx] = (dir[k][j] + 1) % 4;
                ++idx;
            }
        }
    }
}
void draw(int x, int y, int d, int g)
{
    a[y][x] = 1;
    int num = pow(2, g);
    for (int i = 0; i < num; i++)
    {

        if (dir[d][i] == 0)
            ++x;
        if (dir[d][i] == 1)
            --y;
        if (dir[d][i] == 2)
            --x;
        if (dir[d][i] == 3)
            ++y;
        a[y][x] = 1;
    }
}
int main()
{
    int n;
    cin >> n;
    dragonCurve();
    for (int i = 0; i < n; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        draw(x, y, d, g);
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1])
                ++cnt;
        }
    }
    cout << cnt;

    return 0;
}
