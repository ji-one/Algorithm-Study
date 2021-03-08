#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        unordered_map<int, int> um;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            um[x] = 1;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if (um[x])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}