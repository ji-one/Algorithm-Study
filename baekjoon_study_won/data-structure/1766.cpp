#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v[32001];
int inDegree[32001];
int n, m;
void topologySort()
{
    priority_queue<int> pq;

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            pq.push(-i);
    }

    while (!pq.empty())
    {
        int x = -pq.top();
        pq.pop();
        cout << x << ' ';
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i];
            if (--inDegree[y] == 0)
                pq.push(-y);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b); // a -> b
        inDegree[b]++;
    }
    topologySort();
    return 0;
}