#include <iostream>
#include <algorithm>
using namespace std;
int d[12]; // d[i] : i를 1, 2, 3의 합으로 나타내는 방법의 수
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        fill(d, d + n + 1, 0);

        d[1] = 1;
        d[2] = 2;
        d[3] = 4;

        for (int i = 4; i <= n; i++)
        {
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        }

        cout << d[n] << '\n';
    }

    return 0;
}

// n = 1
// 1

// n = 2
// 1 + 1
// 2

// n = 3
// 1 + 1 + 1
// 2 + 1 
// 1 + 2 
// 3

// n = 4
// 