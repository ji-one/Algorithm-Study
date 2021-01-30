#include <iostream>
#include <algorithm>
using namespace std;

int a[1000000];
int n, m;
long long rst = 0;

void binarySearch(int left, int right)
{
    long long sum = 0;
    long long mid = (left + right) / 2;

    if (left > right)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
        {
            sum += (a[i] - mid);
        }
    }

    if (sum >= m)
    {
        rst = max(mid, rst);
        binarySearch(mid + 1, right);
    }
    else
    {
        binarySearch(left, mid - 1);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    binarySearch(0, a[n - 1]);
    cout << rst;

    return 0;
}