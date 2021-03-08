#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// solution
int parent[1000001];
int getParent(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getParent(parent[x]);
}
void unionParent(int x, int y)
{
    x = getParent(x);
    y = getParent(y);
    
    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    while (m--)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0)
        {
            unionParent(a, b);
        }
        if (c == 1)
        {
            if (getParent(a) == getParent(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}