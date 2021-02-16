#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int a[1000000];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int x;
    map<int, int> m;
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
        m[x]++;
    }
    int sz = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        um[it->first] = sz;
        ++sz;
    }

    for (int i = 0; i < n; i++)
    {
        cout << um[a[i]] << ' ';
    }

    return 0;
}