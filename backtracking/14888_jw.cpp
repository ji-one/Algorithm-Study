#include <iostream>
#include <climits>
using namespace std;
int n;
int a[11];
int oper[4]; // + - x ÷
int min_rst = INT_MAX, max_rst = INT_MIN;

void dfs(int idx, int rst)
{
    if (idx == n)
    {
        if (rst > max_rst)
        {
            max_rst = rst;
        }
        if (rst < min_rst)
        {
            min_rst = rst;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (oper[i] > 0)
        {
            --oper[i];
            if (i == 0)
            {
                dfs(idx + 1, rst + a[idx]);
            }
            if (i == 1)
            {
                dfs(idx + 1, rst - a[idx]);
            }
            if (i == 2)
            {
                dfs(idx + 1, rst * a[idx]);
            }
            if (i == 3)
            {
                dfs(idx + 1, rst / a[idx]);
            }
            ++oper[i];
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    }
    dfs(1, a[0]);

    cout << max_rst << '\n'
         << min_rst;

    return 0;
}