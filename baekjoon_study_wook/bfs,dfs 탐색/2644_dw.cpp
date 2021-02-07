// 2644 촌수계산
#include <iostream>
#include <queue>

using namespace std;

int n, a, b, m;
int per[101][101];
int visit[101];
int rst;

bool bfs(int x, int y){
    visit[x] = 1;
    queue<int> q;
    q.push(x);
    
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        if(cx == y){
            rst = visit[cx];
            return true;
        }
        for(int i=1; i<=n; i++){
            if(!visit[i] && per[cx][i]){
                visit[i] = visit[cx] + 1;
                q.push(i);
            }
        }
    }
    return false;
}
int main(){
    cin >> n >> a >> b >> m;
    for(int i=0; i<m; i++){
        int parent, child;
        cin >> parent >> child;
        per[parent][child] = 1;
        per[child][parent] = 1;
    }

    if(bfs(a,b))  cout << rst-1;
    else          cout << -1;
    return 0;
}