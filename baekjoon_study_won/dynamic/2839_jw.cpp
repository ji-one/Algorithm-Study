#include <iostream>
#include <algorithm>
using namespace std;
int d[5001]; // d[i] : i 킬로그램을 배달하는데 최소 봉지 개수
int main()
{
    int n;
    cin >> n;
    d[3] = 1;
    d[5] = 1;

    for (int i = 6; i <= n; i++)
    {
        
        if (!d[i - 5] && !d[i - 3])
            continue;

        if (d[i - 5] && d[i - 3])
            d[i] = min(d[i - 3] + 1, d[i - 5] + 1);
        else if (d[i - 3])
            d[i] = d[i - 3] + 1;
        else
            d[i] = d[i - 5] + 1;
    }

    (d[n] != 0) ? cout << d[n] : cout << -1;

    return 0;
}
