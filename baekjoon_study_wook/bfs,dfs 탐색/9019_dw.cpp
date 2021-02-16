 // 9019 DSLR
#include<iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int t;
int visit[10001];

string bfs(int x, int y){
    queue<pair<int,string>> q;
    q.push({x,""});
    
    while(!q.empty()){
        
        int cx = q.front().first;
        string cs = q.front().second;
        q.pop();
        
        if(cx == y){
            return cs;
        }

        int nx = cx*2;
        if(nx>9999) nx = nx%10000;
        if(visit[nx] == 0){;
            visit[nx] =1;
            q.push({nx, cs+'D'});
        }
        
        nx = cx-1;
        if(nx<0) nx = 9999;
        if(visit[nx] == 0) {
            q.push({nx, cs + 'S'});
            visit[nx] = 1;
        }

        nx= (cx%1000)*10 + (cx/1000);
        if(visit[nx] == 0) {
            q.push({nx,cs + 'L'});
            visit[nx] = 1;
        }

        nx=(cx/10) + (cx%10)*1000;
        if(visit[nx]  == 0) {
            q.push({nx,cs + 'R'});
            visit[nx] = 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        memset(visit,0,sizeof(visit));
        visit[a] = 1;
        cout << bfs(a,b) << '\n';
    }
    return 0;
}