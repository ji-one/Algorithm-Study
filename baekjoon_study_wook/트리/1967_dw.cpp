// 1967 트리의 지름
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > tree[10001];
int visit[10001];

int endPoint = 0;
int maxLen = 0;

void dfs(int node, int len) {
    
    visit[node] =1;
    for(int i=0; i<tree[node].size(); i++) {
        int nextNode = tree[node][i].first;
        int nextLen = tree[node][i].second + len;
        if(!visit[nextNode]) {
            if(maxLen < nextLen) {
                maxLen = nextLen;
                endPoint = nextNode;
            }
            dfs(nextNode, nextLen);
        }
    }
}
int main() {
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int parent, child, edge;
        cin >> parent >> child >> edge;
        tree[parent].push_back({child, edge});
        tree[child].push_back({parent, edge});
    }

    dfs(1, 0);
    fill(visit, visit+n+1, 0);
    dfs(endPoint, 0);
    cout << maxLen;
    return 0;
}