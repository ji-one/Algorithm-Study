#include <iostream>
#include <algorithm>
using namespace std;
int d[301][2]; 
int score[301];
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }

    // 직전에
    // 연속 x
    // 연속 o

    d[1][0] = score[1];
    for (int i = 1; i <= n; i++)
    {
        if (i >= 2)
            d[i][0] = max(d[i - 2][0], d[i - 2][1]) + score[i];
        d[i][1] = d[i - 1][0] + score[i];
    }

    cout << max(d[n][0], d[n][1]);
    return 0;
}