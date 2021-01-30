#include <iostream>
#include <algorithm>
using namespace std;
// solution 봄
// knapsack algorithm
int d[101][100001]; // d[i][j]: i번까지의 물건 탐색, 탐색해서 담은 물건 무게 합 j
int w[101];
int v[101];
int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            d[i][j] = d[i - 1][j];
            if (j - w[i] >= 0)
            {
                d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << d[n][k];
}
