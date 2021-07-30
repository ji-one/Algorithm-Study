// 바이러스

#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<int> com[101];
int visit[101];

void dfs(int num) {

    for(int i=0; i<com[num].size(); i++) {
        if(visit[com[num][i]]) continue;
        visit[com[num][i]] = 1;
        dfs(com[num][i]);
    }

    return ;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        com[v].push_back(u);
        com[u].push_back(v);
    }

    dfs(1);

    int answer = 0;
    for(int i=2; i<=n; i++) {
        if(visit[i]) {
            answer++;
        }
    }
    cout << answer;
    return 0;
}