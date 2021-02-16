#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 100000000
// solution
int dist[501];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, w, s, e, t;
        vector<pair<int, int>> v[501];
        cin >> n >> m >> w; // 지점 수, 도로 수, 웜홀 수
        for (int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            v[s].push_back({e, t});
            v[e].push_back({s, t});
        }
        for (int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            v[s].push_back({e, -t});
        }

        for (int i = 1; i <= n; i++)
            dist[i] = INF;

        bool minusCycle = false;
        dist[1] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (auto &it : v[j])
                {
                    if (dist[it.first] > it.second + dist[j])
                    {
                        dist[it.first] = it.second + dist[j];
                        if (i == n)
                            minusCycle = true;
                    }
                }
            }
        }
        if (minusCycle)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}