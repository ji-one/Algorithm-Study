#include <iostream>
#include <algorithm>
using namespace std;
int d[31];
int main()
{
    int n;
    cin >> n;
    d[0] = 1;
    d[2] = 3;
    for (int i = 4; i <= n; i++)
    {
        d[i] = 3 * d[i - 2];
        for (int j = 4; j <= i; j += 2)
        {
            d[i] += 2 * d[i - j];
        }
    }
    cout << d[n];
}
