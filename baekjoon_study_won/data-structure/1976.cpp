#include <iostream>
using namespace std;
int d[201][201];
int route[1001];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> d[i][j];

    for (int i = 1; i <= n; i++)
        d[i][i] = 1;

    for (int i = 0; i < m; i++)
        cin >> route[i];

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] && d[k][j])
                    d[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m - 1; i++)
    {
        if (d[route[i]][route[i + 1]] == 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}