#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[32001];
int n, m;
int inDegree[32001];
int result[32001];
void topologySort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    // 정렬이 완전히 수행되려면 정확히 n개의 노드 방문
    for (int i = 1; i <= n; i++)
    {
        int x = q.front();
        q.pop();
        result[i] = x;

        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i];
            if (--inDegree[y] == 0)
                q.push(y);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << ' ';
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        inDegree[b]++;
    }
    topologySort();
}