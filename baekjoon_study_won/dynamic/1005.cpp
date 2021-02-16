#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// solution 봄
vector<int> v[1001];
int d[1001];
int inDegree[1001];
int n, k, w;
int rst[1001]; // rst[a] = b : a번 건물 짓는데 걸리는 최소시간
void topologySort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            rst[i] = d[i];
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int j = 0; j < v[x].size(); j++)
        {
            int nx = v[x][j];
            rst[nx] = max(rst[nx], rst[x] + d[nx]);
            if (--inDegree[nx] == 0)
            {
                q.push(nx);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i];
        }
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            inDegree[b]++;
        }

        cin >> w;
        topologySort();
        cout << rst[w] << '\n';

        // init
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
            inDegree[i] = 0;
            rst[i] = 0;
        }
    }
}