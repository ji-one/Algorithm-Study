// 4803 트리

#include <iostream>
#include <vector>

using namespace std;

// vector<int> parent[501];
int parent[501];
int cycle[501];

int getParent(int node) {
    if(parent[node]==node) return node;
    return parent[node] = getParent(parent[node]);
}

void _union(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a<b) parent[b] = a;
    else    parent[a] = b;
}

bool _find(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a==b) return true;
    else     return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    int testCase = 1;
    while(1) {
        cin >> n >> m;
        if(n==0 && m==0) {
            break;
        }
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
        for(int i=0; i<m; i++) {
            int u,v;
            cin >> u >> v;
            if(_find(u,v)) {
                int x = getParent(u);
                cycle[x] = 1;
            }
            _union(u,v);
            if(cycle[u]==1) cycle[v]=1;
            if(cycle[v]==1) cycle[u]=1;
        }

        int cnt = 0;
        for(int i=1; i<=n; i++) {
            parent[i] = getParent(i);
            if(parent[i] == i) {
                if(cycle[i] == 0) {
                    cnt++;
                } 
            }
            // cout << parent[i] << ' ';
        }
        // cout << '\n';
        cout << "Case " << testCase << ": ";
        if(cnt == 0) {
            cout << "No trees." << '\n';
        } else if(cnt == 1) {
            cout << "There is one tree." << '\n';
        } else {
            cout << "A forest of " << cnt << " trees." << '\n';
        }
        testCase++;
        fill(cycle, cycle +n+1, 0);
    }
    return 0;
}