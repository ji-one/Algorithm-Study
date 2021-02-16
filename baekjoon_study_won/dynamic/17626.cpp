#include <iostream>
#include <cmath>
using namespace std;
int d[50001];
int main()
{
    int n;
    cin >> n;
    fill(&d[0], &d[50000], 10);
    for (int i = 1; i <= n; i++)
    {
        int x = sqrt(i);
        if (x * x == i)
            d[i] = 1;
        else
        {
            for (int j = 1; j * j <= i; j++)
                d[i] = min(d[i], d[j * j] + d[i - j * j]);
        }
    }
    cout << d[n];
    return 0;
}