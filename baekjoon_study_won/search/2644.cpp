#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b;
int d[101][101];
int INF = 100000000;
int main()
{
    cin >> n;
    cin >> a >> b;
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        d[x][y] = 1; // x가 부모
        d[y][x] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    if (d[a][b] == INF)
        cout << -1;
    else
        cout << d[a][b];
}