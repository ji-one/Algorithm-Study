#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// solution 봄
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end(), compare);
    int cnt = 0;

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (v[i].second <= v[j].first)
        {
            ++cnt;
            i = j;
        }
    }
    cout << cnt + 1;
    return 0;
}