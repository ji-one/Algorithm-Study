#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, rst;
int map[51][51];
int visit[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void bfs(int x, int y){
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({0, {x,y}});
    visit[x][y] = 1;

    while(!pq.empty()){
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        int cb = -pq.top().first;
        pq.pop();
        if(cx == n-1 && cy == n-1){
            rst = cb;
            break;
        }
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && !visit[nx][ny] && map[nx][ny] == 1){
                pq.push({-cb,{nx,ny}});
                visit[nx][ny] = 1;
            }
            else if(isInside(nx,ny) && !visit[nx][ny] && map[nx][ny] == 0){
                pq.push({-cb-1,{nx,ny}});
                visit[nx][ny] = 1;
            }
        }
    }

}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            map[i][j] = s[j] - '0';
        }
    }
    bfs(0,0);
    cout << rst;
    return 0;
}