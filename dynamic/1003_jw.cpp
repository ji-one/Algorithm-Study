#include <iostream>
using namespace std;
int d[41][2]; // d[i][0] : 0의 개수, d[i][1] : 1의 개수
int main()
{
    int t;
    cin >> t;

    d[0][0] = 1;
    d[1][1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        d[i][0] = d[i - 1][0] + d[i - 2][0];
        d[i][1] = d[i - 1][1] + d[i - 2][1];
    }

    while (t--)
    {
        int n;
        cin >> n;
        cout << d[n][0] << ' ' << d[n][1] << '\n';
    }
    return 0;
}