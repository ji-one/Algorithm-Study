// 듣보잡
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> map;
    string name;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        map[name]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        map[name]++;
    }
    vector<string> v;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (it->second == 2)
        {
            v.push_back(it->first);
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }
}