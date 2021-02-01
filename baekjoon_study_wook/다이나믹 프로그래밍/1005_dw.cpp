// 1005 ACM Craft --- 솔루션봄
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int t,n,k;
int build[1001];
vector<int> v[1001];
int edge[1001];
int dp[1001];

void bfs(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(edge[i] == 0){
            q.push(i);
            dp[i] = build[i];
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++){
            int nx = v[x][i];
            dp[nx] = max(dp[nx], dp[x]+build[nx]);
            edge[nx]--;
            if(edge[nx]==0) q.push(nx);
        }
    }
    
}
int main(){
    cin >> t;
    while(t--){
        memset(build,0,sizeof(build));
        memset(dp,0,sizeof(dp));
        memset(edge,0,sizeof(edge));
        for(int i=0; i<1001; i++) v[i].clear();


        int ans = 0;
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            cin >> build[i];
        }
        for(int i=0; i<k; i++){
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            edge[y]++;
        }
        int w;
        cin >> w;        
        bfs();

        cout << dp[w]<< '\n';

    }
    return 0;
}