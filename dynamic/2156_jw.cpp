#include <iostream>
using namespace std;
int a[10001];
int d[10001][2]; //연속 x, 연속 o
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    d[1][0] = a[1];
    d[2][0] = a[2];
    d[2][1] = a[1] + a[2];

    for (int i = 3; i <= n; i++)
    {
        d[i][0] = max(d[i - 2][1], max(d[i - 2][0], max(d[i - 3][0], d[i - 3][1]))) + a[i];
        d[i][1] = d[i - 1][0] + a[i];
    }
    int rst = 0;
    for (int i = 1; i <= n; i++)
    {
        rst = max(rst, max(d[i][0], d[i][1]));
    }
    cout << rst;
    return 0;

}