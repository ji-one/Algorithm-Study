#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
int n, k, res = INT_MAX;
int visited[200001];
void bfs(int x)
{
    priority_queue<pair<int, int>> pq; // 시간이 작은 순으로 정렬
    pq.push({0, x});
    fill(&visited[0], &visited[200001], -1);
    while (!pq.empty())
    {
        int cx = pq.top().second;
        int t = -pq.top().first;
        
        pq.pop();
        if (cx == k)
        {
            res = min(res, t);
        }
        if (t > res)
            return;

        if (cx <= k && (visited[2 * cx] == -1 || visited[2 * cx] > t))
        {
            visited[2 * cx] = t;
            pq.push({-t, 2 * cx});
        }
        if (cx - 1 >= 0 && (visited[cx - 1] == -1 || visited[cx - 1] > t))
        {
            visited[cx - 1] = t + 1;
            pq.push({-(t + 1), cx - 1});
        }

        if (cx + 1 <= k && (visited[cx + 1] == -1 || visited[cx + 1] > t))
        {
            visited[cx + 1] = t + 1;
            pq.push({-(t + 1), cx + 1});
        }
    }
}
int main()
{
    cin >> n >> k;
    bfs(n);
    cout << res;
    return 0;
}