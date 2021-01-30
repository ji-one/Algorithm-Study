#include <iostream>
#include <algorithm>
using namespace std;
int d[1001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            d[i] = max(d[i], d[j] + d[i - j]);
        }
    }
    cout << d[n];
    return 0;
}