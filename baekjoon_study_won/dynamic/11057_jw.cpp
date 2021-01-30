#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[1001][10]; // d[i][j] : i자리 수 중 끝자리가 j인 것에 대한 오르막수 
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++)
    {
        d[1][i] = 1;
    }
    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                d[k][i] += d[k - 1][j];  
                d[k][i] %= 10007;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        sum += d[n][i];
        sum %= 10007;
    }
    cout << sum;

    return 0;
}