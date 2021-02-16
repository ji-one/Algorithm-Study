#include <iostream>
#include <algorithm>
using namespace std;
// solution 봄
int d[100001][3];
int main()
{
    int n;
    cin >> n;
/*
1. n번째 줄에 사자가 모두 없는 경우 d[n][0] = d[n-1][0] + d[n-1][1] + d[n-1][2]
2. n번째 줄에 왼쪽 칸에만 사자가 있는 경우 d[n][1] = d[n-1][0] + d[n-1][2]
3. n번째 줄에 오른쪽 칸에만 사자가 있는 경우 d[n][2] = d[n-1][0] + d[n-1][1]
*/
    int mod = 9901;
    d[1][0] = d[1][1] = d[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % mod;
        d[i][1] = (d[i - 1][0] + d[i - 1][2]) % mod;
        d[i][2] = (d[i - 1][0] + d[i - 1][1]) % mod;
    }

    cout << (d[n][0] + d[n][1] + d[n][2]) % mod;
}