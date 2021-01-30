#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[101];
bool checked[101];
int bfs(int x)
{
    int cnt = 0;
    queue<int> q;
    q.push(x);
    checked[x] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (!checked[next])
            {
                checked[next] = true;
                q.push(next);
            }
        }
        ++cnt;
    }

    return cnt - 1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout << bfs(1);
    return 0;
}