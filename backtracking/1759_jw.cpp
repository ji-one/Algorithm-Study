#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char a[15];
char p[15];
void dfs(int idx, int cnt, int con, int vow)
{
    if (cnt == l)
    {
        if (vow >= 1 && con >= 2)
        {
            for (int i = 0; i < l; i++)
                cout << p[i];

            cout << '\n';
        }
        return;
    }

    for (int i = idx; i < c; i++)
    {
        p[cnt] = a[i];
        if (p[cnt] == 'a' || p[cnt] == 'e' || p[cnt] == 'i' || p[cnt] == 'o' || p[cnt] == 'u')
            dfs(i + 1, cnt + 1, con, vow + 1);
        else
            dfs(i + 1, cnt + 1, con + 1, vow);
    }
}
int main()
{
    cin >> l >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> a[i];
    }
    sort(a, a + c);
    dfs(0, 0, 0, 0);
    return 0;
}