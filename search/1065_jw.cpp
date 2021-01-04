#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, cnt = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string num = to_string(i);
        bool flag = true;

        if (num.length() >= 2)
        {
            int d = num[1] - num[0];
            for (int i = 1; i < num.length() - 1; i++)
            {
                if (num[i] + d != num[i + 1])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            ++cnt;
    }
    cout << cnt;

    return 0;
}