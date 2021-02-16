#include <iostream>
#include <algorithm>
#include <cmath>
int a[10];
int tmp[10];
bool checked[10];
int res, n;
using namespace std;
int calc()
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += abs(tmp[i] - tmp[i + 1]);
    }
    return sum;
}
void dfs(int cnt)
{
    if (cnt == n)
    {
        res = max(res, calc());
        // for (int i = 0; i < n; i++)
        // {
        //     cout << tmp[i] << ' ';
        // }
        // cout << '\n';
    }

    for (int i = 0; i < n; i++)
    {
        if (!checked[i])
        {
            tmp[cnt] = a[i];
            checked[i] = true;
            dfs(cnt + 1);
            checked[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0);
    cout << res;
    return 0;
}