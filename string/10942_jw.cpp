#include <iostream>
#include <string>
using namespace std;
int a[2001];
int dp[2001][2001]; // dp[s][e] : s ~ e 까지 팰린드롬 여부
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int d = 0; d < n; d++)
    {
        for (int i = 1; i <= n - d; i++)
        {
            if (d == 0)
                dp[i][i + d] = 1;
            else if (d == 1 && a[i] == a[i + d])
                dp[i][i + d] = 1;
            else if (a[i] == a[i + d] && dp[i + 1][i + d - 1])
                dp[i][i + d] = 1;
        }
    }

    int m, s, e;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}