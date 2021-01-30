#include <iostream>
#include <algorithm>
using namespace std;
int a[100];
int d[100001];
int main()
{

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        d[a[i]] = 1;
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= a[j] && d[i - a[j]] != 0)
            {
                if (d[i] == 0)
                    d[i] = d[i - a[j]] + 1;
                d[i] = min(d[i], d[i - a[j]] + 1);
            }
        }
    }

    if (d[k] == 0)
        cout << -1;
    else
        cout << d[k];

    return 0;
}