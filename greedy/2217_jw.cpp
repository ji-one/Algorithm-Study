#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (res < a[n - i] * i)
        {
            res = a[n - i] * i;
        }
    }
    cout << res;
}