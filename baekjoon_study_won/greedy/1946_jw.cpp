#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// solution 봄
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        int cnt = 1;

        int min = v[0].second;
        for (int i = 1; i < n; i++)
        {
            if (v[i].second < min)
            {
                min = v[i].second;
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
}
