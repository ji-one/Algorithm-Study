#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
vector<pair<int, int>> v[20001];
int d[20001];
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
    int V, E, K;
    cin >> V >> E >> K;

    for (int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }

    for (int i = 1; i <= V; i++)
    {
        d[i] = INT_MAX;
    }

    dijkstra(K);

    for (int i = 1; i <= V; i++)
    {
        if (d[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }

    return 0;
}