#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int item[101];
vector<pair<int, int>> v[101];
int d[101];
int INF = 100000000;
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
            if (d[next] > next_distance)
            {
                d[next] = next_distance;
                pq.push({-next_distance, next});
            }
        }
    }
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
        cin >> item[i];

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        v[a].push_back({b, l});
        v[b].push_back({a, l});
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        fill(&d[0], &d[n + 1], INF);
        dijkstra(i);
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (d[j] <= m)
                cnt += item[j];
        }
        res = max(res, cnt);
    }
    cout << res;
    return 0;
}