#include <iostream>
using namespace std;
int cost[100001];
int dist[100001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> dist[i]; // i->i+1 거리
    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    int min = 1000000000;
    long long res = 0;
    for (int i = 1; i < n; i++)
    {
        if (cost[i] < min)
            min = cost[i];
        res += (long long)dist[i] * min;
    }
    cout << res;
    return 0;
}