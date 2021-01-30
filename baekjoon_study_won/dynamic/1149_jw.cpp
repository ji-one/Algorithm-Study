#include <iostream>
#include <algorithm>
using namespace std;
int cost[1001][3]; // R G B
int d[1001][3];    // d[i][0] : i번째 집을 R로 칠하는 경우 i번째까지의 비용
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        d[i][0] = min(d[i - 1][1] + cost[i][0], d[i - 1][2] + cost[i][0]);
        d[i][1] = min(d[i - 1][0] + cost[i][1], d[i - 1][2] + cost[i][1]);
        d[i][2] = min(d[i - 1][0] + cost[i][2], d[i - 1][1] + cost[i][2]);
    }
    cout << min(d[n][0], min(d[n][1], d[n][2]));

    return 0;
}