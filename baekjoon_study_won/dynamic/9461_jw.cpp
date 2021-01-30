#include <iostream>
using namespace std;
long long p[101];
int main()
{
    int t, n;
    cin >> t;

    p[1] = 1;
    p[2] = 1;
    p[3] = 1;

    for (int i = 4; i <= 100; i++)
    {
        p[i] = p[i - 3] + p[i - 2];
    }

    while (t--)
    {
        cin >> n;
        cout << p[n] << '\n';
    }

    return 0;
}
