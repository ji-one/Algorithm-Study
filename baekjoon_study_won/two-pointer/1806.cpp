#include <iostream>
using namespace std;
int a[100001];
int main()
{
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int start = 0, end = 0;
    int len = n + 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ++end;
        if (sum >= s)
        {
            len = min(len, end - start);
            while (1)
            {
                sum -= a[start];
                ++start;
                if (sum >= s)
                    len = min(len, end - start);
                else
                    break;
            }
        }
    }
    if (len == n + 1)
        cout << 0;
    else
        cout << len;
}