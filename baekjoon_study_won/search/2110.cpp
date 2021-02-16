#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// solution
int a[200000];
int n, c;
void binarySearch(int left, int right)
{
    int mid = (left + right) / 2;

    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] - a[i] >= mid)
            {
                ++cnt;
                i = j - 1;
                break;
            }
        }
    }

    if (left >= right)
    {
        if (cnt >= c)
            cout << mid;
        else
            cout << mid - 1;
        return;
    }
    if (cnt >= c)
        binarySearch(mid + 1, right);
    else
        binarySearch(left, mid - 1);
}
int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int d = a[n - 1] - a[0];
    binarySearch(0, d);
    return 0;
}