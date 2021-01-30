#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
vector<pair<int, int>> v[1001];
int d[1001];
void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    d[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (d[current] < distance)
            continue;

        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int next_distance = distance + v[current][i].second;

            if (next_distance < d[next])
            {
                d[next] = next_distance;
                pq.push({-next_distance, next});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        v[s].push_back({e, w});
    }
    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= n; i++)
        d[i] = INT_MAX;

    dijkstra(a);
    cout << d[b];
}