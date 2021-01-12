#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int a[21][21];
int n;
int rst = INT_MAX;
int team[10];

int calcDiff()
{
    int t[20] = {
        0,
    };
    int t1 = 0,
        t2 = 0;
    for (int i = 0; i < n / 2; i++)
    {
        t[team[i]] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i] && t[j])
                t1 += (a[i][j] + a[j][i]);
            if (!t[i] && !t[j])
                t2 += (a[i][j] + a[j][i]);
        }
    }
    return abs(t1 - t2);
}
void dfs(int idx, int cnt)
{
    if (cnt == n / 2)
    {
        int diff = calcDiff();
        rst = rst > diff ? diff : rst;
        return;
    }
    for (int i = idx; i < n; i++)
    {
        team[cnt] = i;
        dfs(i + 1, cnt + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    dfs(0, 0);
    cout << rst;
    return 0;
}