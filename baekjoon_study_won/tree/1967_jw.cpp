#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> v[10001];
bool visited[10001];
int end_node, sum;
void dfs(int root, int weight)
{
    visited[root] = true;

    if (sum < weight)
    {
        end_node = root;
        sum = weight;
    }

    for (int i = 0; i < v[root].size(); i++)
    {
        int c = v[root][i].first;
        int w = v[root][i].second;
        if (!visited[c])
        {
            dfs(c, weight + w);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        v[s].push_back({e, w});
        v[e].push_back({s, w});
    }
    dfs(1, 0);
    sum = 0;
    memset(visited, false, sizeof(visited));
    dfs(end_node, 0);
    cout << sum;
    return 0;
}