#include <iostream>
using namespace std;
long long d[91][2]; // 가장 마지막 수 0 , 1
int main()
{
    int n;
    cin >> n;
    d[1][1] = 1;
    d[2][0] = 1;
    for (int i = 3; i <= n; i++)
    {
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }

    cout << d[n][0] + d[n][1];
    return 0;
}
