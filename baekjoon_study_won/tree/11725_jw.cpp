#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100001];
bool visited[100001];
int parent[100001];
void findParent(int root)
{
    visited[root] = true;
    for (int i = 0; i < v[root].size(); i++)
    {
        int child = v[root][i];
        if (!visited[child])
        {
            parent[child] = root;
            findParent(child);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    findParent(1);
    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << '\n';
    }
    return 0;
}