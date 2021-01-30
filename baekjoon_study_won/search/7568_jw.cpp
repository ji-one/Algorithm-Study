#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<pair<int, int>> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (v[i].first < v[j].first && v[i].second < v[j].second)
                {
                    ++cnt;
                }
            }
        }
        cout << cnt + 1 << ' ';
    }
}