#include <iostream>
using namespace std;
int d[101][11]; // d[i][j]: 길이가 i이고 끝자리 수가 j인 계단 수
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++)
    {
        d[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {

            d[i][j] += d[i - 1][j + 1];
            d[i][j] %= 1000000000;
            if (j != 0)  
            {
                d[i][j] += d[i - 1][j - 1];
                d[i][j] %= 1000000000;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        sum += d[n][i];
        sum %= 1000000000;
    }
    cout << sum;
    return 0;
}