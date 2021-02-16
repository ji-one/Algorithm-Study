#include <iostream>
#include <algorithm>
using namespace std;
int d[1001];
int main()
{
    int n;
    cin >> n;
    d[2] = 1; //0 : SK, 1: CY
    d[4] = 1;
    for (int i = 4; i <= n; i++)
    {
        if (d[i - 1] == 0 || d[i - 3] == 0)
            d[i] = 1;
        else
            d[i] = 0;
    }
    
    if (d[n] == 0)
        cout << "SK";
    else
        cout << "CY";
    return 0;
}