#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> e[1001];
bool visited[1001];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size(); i++)
        {
            int nx = e[x][i];
            if (!visited[nx])
            {
                visited[nx] = true;
                q.push(nx);
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
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int rst = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            ++rst;
        }
    }
    cout << rst;
    return 0;
}