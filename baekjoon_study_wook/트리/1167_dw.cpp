// 1167 트리의 지름
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > tree[100001];
int visit[100001];

int maxLen;
int ver;

void dfs(int node, int len) {

    visit[node] = 1;
    for(int i=0; i<tree[node].size(); i++) {
        int nextNode = tree[node][i].first;
        if(!visit[nextNode]) {
            int nextLen = len + tree[node][i].second;
            // maxLen = max(maxLen, len);
            if(maxLen < nextLen) {
                maxLen = nextLen;
                ver = nextNode;
            }
            dfs(nextNode, nextLen);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int v1;
        cin >> v1;
        while(1) {
            int v2,e;
            cin >> v2;
            if(v2 == -1) break;
            cin >> e;
            
            tree[v1].push_back({v2, e});
            
        }
    }

    dfs(1, 0);
    fill(visit, visit + n + 1, 0);

    maxLen = 0;
    dfs(ver, 0);
    cout << maxLen;
    return 0;
}