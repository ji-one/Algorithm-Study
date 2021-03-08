#include <iostream>
using namespace std;
int d[100][100];
int INF = 100000000;
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> d[i][j];
            if (d[i][j] == 0)
                d[i][j] = INF;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] >= INF)
                d[i][j] = 0;
            else
                d[i][j] = 1;
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}