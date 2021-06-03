// 11725 트리의 부모 찾기

#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int parent[100001];
int visit[100001];

void dfs(int node) {
    for(int i=0; i<tree[node].size(); i++) {
        int nextNode = tree[node][i];
        if(!visit[nextNode]) {
            visit[nextNode] = 1;
            parent[nextNode] = node;
            dfs(nextNode);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);

    }

    dfs(1);

    for(int i=2; i<=n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}