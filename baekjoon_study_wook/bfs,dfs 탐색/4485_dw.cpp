// 4485 녹색 옷 입은 애가 젤다지?

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, rst;
int map[150][150];
int visit[150][150];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void bfs(int x, int y){
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-map[x][y],{x,y}});
    visit[x][y] = 1;
    while(!pq.empty()){
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        int cc = -pq.top().first;
        pq.pop();
        // cout << cc <<'\n';
        if(cx == n-1 && cy == n-1) {
            rst = cc;
            break;
        }
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && !visit[nx][ny]){
                pq.push({-(cc+map[nx][ny]),{nx,ny}});
                visit[nx][ny] = 1;
            }
        }
    }

}

int main(){
    int idx = 1;
    while(1){
        cin >> n;
        if(n == 0) break;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        
        for(int i=0; i<n; i++){
            for(int j=0 ;j<n; j++){
                cin >> map[i][j];
            }
        }

        bfs(0,0);

        cout << "Problem " << idx << ": " << rst << '\n';
        idx++;
    }
    return 0;
}