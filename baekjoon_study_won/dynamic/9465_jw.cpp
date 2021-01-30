#include <iostream>
#include <algorithm>
using namespace std;
int a[2][100000];
int d[2][100000];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                d[i][j] = 0;
            }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (i >= 1)
                    d[j][i] = d[(j + 1) % 2][i - 1];
                if (i >= 2)
                    d[j][i] = max(d[j][i], max(d[0][i - 2], d[1][i - 2]));
                d[j][i] += a[j][i];
                res = res < d[j][i] ? d[j][i] : res;
            }
        }
        cout << res << '\n';
    }
}