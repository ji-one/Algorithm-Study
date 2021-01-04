#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > sum + 1)
        {
            break;
        }
        sum += a[i];
    }

    cout << sum + 1;
    return 0;
}
