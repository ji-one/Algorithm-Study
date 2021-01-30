#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> t[100001];
bool visited[100001];
int end_node, sum;
void dfs(int root, int weight)
{
    visited[root] = true;

    if (sum < weight)
    {
        end_node = root;
        sum = weight;
    }

    for (int i = 0; i < t[root].size(); i++)
    {
        int c = t[root][i].first;
        int w = t[root][i].second;
        if (!visited[c])
        {
            dfs(c, weight + w);
        }
    }
}

int main()
{
    int v;
    cin >> v;
    for (int i = 0; i < v; i++)
    {
        int s, e, d;
        cin >> s;
        while (1)
        {
            cin >> e;
            if (e == -1)
                break;
            cin >> d;
            t[s].push_back({e,d});
        }
    }

    dfs(1, 0);
    sum = 0;
    memset(visited, false, sizeof(visited));
    dfs(end_node, 0);
    cout << sum;
    return 0;
}