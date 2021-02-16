#include <iostream>
#include <algorithm>
using namespace std;
//solution
//<x, y> = k 번째 해
// k%M = x, k%N = y
// ans = x
// ans' = ans + m
// ans'' = ans' + m

// ans = <x, ?>
// 조건 ans <= lcm(m, n)
int lcm(int m, int n)
{
    int a = m;
    int b = n, tmp;

    while (b)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }

    return (m * n) / a;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int lcmNum = lcm(M, N);
        int ans = x;
        y %= N;
        while (ans <= lcmNum && ans % N != y)
        {
            ans += M;
        }

        if (ans > lcmNum)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}