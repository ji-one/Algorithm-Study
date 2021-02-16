#include <iostream>
#include <algorithm>
using namespace std;
int a[100001][4];
int dp1[2][4]; // max
int dp2[2][4]; // min
int INF = 100000000;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 3; j++)
            cin >> a[i][j];

    for (int i = 1; i <= 3; i++)
    {
        dp1[0][i] = a[1][i];
        dp2[0][i] = a[1][i];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {

            if (j == 1)
            {
                dp1[1][j] = max(dp1[0][j + 1], dp1[0][j]);
                dp2[1][j] = min(dp2[0][j + 1], dp2[0][j]);
            }
            if (j == 2)
            {
                dp1[1][j] = max(max(dp1[0][j + 1], dp1[0][j - 1]), dp1[0][j]);
                dp2[1][j] = min(min(dp2[0][j + 1], dp2[0][j - 1]), dp2[0][j]);
            }
            if (j == 3)
            {
                dp1[1][j] = max(dp1[0][j - 1], dp1[0][j]);
                dp2[1][j] = min(dp2[0][j - 1], dp2[0][j]);
            }

            dp1[1][j] += a[i][j];
            dp2[1][j] += a[i][j];
        }
        // 현재를 이전으로
        for (int k = 1; k <= 3; k++)
        {
            dp1[0][k] = dp1[1][k];
            dp2[0][k] = dp2[1][k];
        }
    }

    cout << max(dp1[0][1], max(dp1[0][2], dp1[0][3])) << ' ';
    cout << min(dp2[0][1], min(dp2[0][2], dp2[0][3]));

    return 0;
}