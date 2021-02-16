#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> um;
    string s1, s2;
    while (n--)
    {
        cin >> s1 >> s2;
        um[s1] = s2;
    }

    while (m--)
    {
        cin >> s1;
        cout << um[s1] << '\n';
    }

    return 0;
}