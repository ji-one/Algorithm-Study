#include <iostream>
#include <vector>
using namespace std;
vector<int> v[500001];
int visited[500001];
void dfs(int start)
{
    for (int i = 0; i < v[start].size(); i++)
    {
        int next = v[start][i];
        if (!visited[next])
        {
            visited[next] = visited[start] + 1;
            dfs(next);
        }
    }
}
int main()
{
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    visited[1] = 1;
    dfs(1);

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == 1)
            sum += (visited[i] - 1);
    }

    if (!(sum % 2))
        cout << "No";
    else
        cout << "Yes";
}