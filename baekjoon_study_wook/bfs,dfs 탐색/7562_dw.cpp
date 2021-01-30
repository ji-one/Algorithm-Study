//7562 나이트의 이동
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int t;
int l;  // 체스판 길이
int visit[301][301];
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,-2,-1,1,2};

void bfs(int a,int b, int x, int y){
    queue<pair<int, int>> q;
    q.push({a,b});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        if(cx == x && cy == y){
            break;
        }
        for(int i=0; i<8; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx>=0 && nx<l && ny>=0 && ny<l){
                if(!visit[nx][ny]){
                    visit[nx][ny] = visit[cx][cy] + 1;
                    q.push({nx,ny});
                }
            }
        }

    }
}
int main(){
    cin >> t;
    while(t--){  
        memset(visit,0,sizeof(visit));  
        cin >> l;
        int cx, cy, nx, ny; // 나이트 위치 (cx,cy)  (nx,ny)
        cin >> cx >>cy >> nx>> ny;
        bfs(cx,cy,nx,ny);
        cout << visit[nx][ny] << '\n';

    }
    return 0;
}