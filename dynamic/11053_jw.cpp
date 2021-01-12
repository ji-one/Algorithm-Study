#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int d[1001];
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
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
            {
                d[i] = max(d[j] + 1, d[i]);
            }
        }
        d[i] = max(1, d[i]);
    }
    sort(d + 1, d + n + 1);
    cout << d[n];
    return 0;
}