#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v[1001];
int d[1001];
int dijkstra(int start, int end)
{
    priority_queue<pair<int, int>> pq;
    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cx = pq.top().second;
        int cc = -pq.top().first;
        pq.pop();
        if (d[cx] < cc)
            continue;
        for (int i = 0; i < v[cx].size(); i++)
        {
            int nx = v[cx][i].first;
            int nc = cc + v[cx][i].second;
            if (d[nx] > nc)
            {
                d[nx] = nc;
                pq.push({-nc, nx});
            }
        }
    }
    return d[end];
}
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        v[s].push_back({e, t});
    }
    int max_val = 0;
    for (int i = 1; i <= n; i++)
    {
        fill(&d[0], &d[n + 1], 100000000);
        int go = dijkstra(i, x);
        fill(&d[0], &d[n + 1], 100000000);
        int back = dijkstra(x, i);
        max_val = max(max_val, go + back);
    }
    cout << max_val;
}