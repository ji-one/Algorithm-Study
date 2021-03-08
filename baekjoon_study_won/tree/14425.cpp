#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> um;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        um[s] = 1;
    }
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (um[s])
            ++res;
    }
    cout << res;
    return 0;
}