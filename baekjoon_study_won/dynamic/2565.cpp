#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int d[101], res;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        d[i] = 1;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (v[i].second > v[j].second)
            {
                d[i] = max(d[i], d[j] + 1);
                res = max(d[i], res);
            }
        }
    }

    cout << n - res;
    return 0;
}