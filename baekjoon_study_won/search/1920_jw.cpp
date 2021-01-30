#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];

int binarySearch(int target, int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    else
    {
        int mid = (left + right) / 2;

        if (a[mid] == target)
        {
            return 1;
        }
        else if (target < a[mid])
        {
            return binarySearch(target, left, mid - 1);
        }
        else
        {
            return binarySearch(target, mid + 1, right);
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        cout << binarySearch(x, 0, n - 1) << '\n';
    }

    return 0;
}