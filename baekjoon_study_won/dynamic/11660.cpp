#include <iostream>
#include <algorithm>
using namespace std;
int a[1025][1025];
int d[1025][1025]; // d[i][j] : i행 0열 ~ i행 j열까지의 합 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, x1, y1, x2, y2;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            d[i][j] += (d[i][j - 1] + a[i][j]);
        }
    }
    while (m--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for (int i = x1; i <= x2; i++)
        {
            sum += (d[i][y2] - d[i][y1 - 1]);
        }
        cout << sum << '\n';
    }

    return 0;
}