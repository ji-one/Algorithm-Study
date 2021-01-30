#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int d[100001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = max(d[i - 1] + a[i], a[i]);
    }
    int rst = d[1];
    for (int i = 2; i <= n; i++)
    {
        rst = (rst < d[i] ? d[i] : rst);
    }
    cout << rst;
    return 0;
}