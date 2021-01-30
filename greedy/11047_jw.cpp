#include <iostream>
using namespace std;
int cost[11];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += (k / cost[i]);
        k -= (k / cost[i]) * cost[i];
        if (k == 0)
            break;
    }
    cout << sum;
}