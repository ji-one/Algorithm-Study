// 11437 LCA

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[50001];
int visit[50001];
int parent[50001];
int depth[50001];

int LCA(int u, int v) {
    if(depth[u] > depth[v]) {
        swap(u, v);
    }

    while(depth[u] != depth[v]) {
        v = parent[v];
    }

    while(u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}
void dfs(int node, int level) {
    visit[node] = 1;
    depth[node] = level;
    for(int i=0; i<v[node].size(); i++) {
        int childNode = v[node][i];
        if(!visit[childNode]) {
            parent[childNode] = node;
            dfs(childNode, level+1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 1);
    
    cin >> m;
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << LCA(a,b) << '\n';
    }
    return 0;
}