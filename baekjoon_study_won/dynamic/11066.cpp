#include <iostream>
#include <algorithm>
using namespace std;
// solution
// d[a][b] : a부터 b까지 페이지를 합친 최솟값
// sum[a] : 0부터 a까지 페이지를 더한 값
// d[a][a] = cost[a]
// d[a][a] = sum[a] - sum[a-1]
// d[a][a+1] = sum[a+1] - sum[a-1]
// d[a][a+2] = min(d[a][a] + d[a+1][a+2], d[a][a+1] + d[a+2][a+2])
int dp[501][501];
int cost[501];
int sum[501];
int INF = 200000000;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }

        for (int d = 1; d < n; d++)
        {
            for (int s = 1; s + d <= n; s++)
            {
                int e = s + d;
                dp[s][e] = INF;

                for (int m = s; m < e; m++)
                {
                    dp[s][e] = min(dp[s][e], dp[s][m] + dp[m + 1][e] + sum[e] - sum[s - 1]);
                }
            }
        }
        cout << dp[1][n] << '\n';
    }
    return 0;
}