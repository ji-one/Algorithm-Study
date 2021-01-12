#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool visited[10];
void dfs(int cnt, vector<int> v)
{
    if (cnt == m)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v.push_back(i);
            dfs(cnt + 1, v);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<int> v;
    dfs(0, v);
    return 0;
}