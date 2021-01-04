#include <iostream>
#include <algorithm>
using namespace std;
int d[1000001]; // d[i] : i를 1로 만드는 연산 횟수의 최솟값
int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + 1;

        if (!(i % 3))
        {
            d[i] = min(d[i], d[i / 3] + 1);
        }
        if (!(i % 2))
        {
            d[i] = min(d[i], d[i / 2] + 1);

        }
    }
    cout << d[n];
    return 0;
}