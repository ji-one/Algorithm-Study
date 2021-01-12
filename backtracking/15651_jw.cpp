#include <iostream>
using namespace std;
int n, m;
int p[10];
void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << p[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        p[cnt] = i;
        dfs(cnt + 1);
    }
}

int main()
{
    cin >> n >> m;
    dfs(0);
    return 0;
}