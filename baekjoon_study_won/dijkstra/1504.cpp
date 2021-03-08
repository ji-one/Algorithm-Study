#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v[1001];
int d[1001];
int INF = 100000000;
int n, e;
int dijkstra(int start, int end)
{
    fill(&d[1], &d[n + 1], INF);
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
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;

    int cost1 = 0, cost2 = 0;
    cost1 += dijkstra(1, v1);
    cost1 += dijkstra(v1, v2);
    cost1 += dijkstra(v2, n);

    cost2 += dijkstra(1, v2);
    cost2 += dijkstra(v2, v1);
    cost2 += dijkstra(v1, n);

    int res = min(cost1, cost2);
    if (res >= INF)
        cout << -1;
    else
        cout << res;
}
