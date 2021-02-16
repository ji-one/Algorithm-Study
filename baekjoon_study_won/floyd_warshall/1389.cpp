#include <iostream>
using namespace std;
int d[100][100];
int INF = 100000000;
int main()
{
    int n, m, a, b;
    cin >> n >> m;
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
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    int Min = INF, res;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += d[i][j];
        }
        if (Min > sum)
        {
            Min = sum;
            res = i;
        }
    }
    cout << res;
}