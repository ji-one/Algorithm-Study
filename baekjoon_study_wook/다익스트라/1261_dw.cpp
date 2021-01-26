// 1261 알고스팟  솔루션 봄
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int INF = 10000;
int n,m;
int map[101][101];
int dist[101][101]; // 벽을 부순 개수 저장

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    dist[x][y] = 0;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx +dx[i];
            int ny = cy +dy[i];
            if(isInside(nx, ny)){
                if(map[nx][ny] == 1){
                    if(dist[nx][ny] > dist[cx][cy] +1){
                        dist[nx][ny] = dist[cx][cy] +1;
                        q.push({nx,ny});
                    }
                }
                else if(map[nx][ny] == 0){
                    if(dist[nx][ny] > dist[cx][cy]){
                        dist[nx][ny] = dist[cx][cy];
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
}
int main(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j]-'0';
            dist[i][j] = INF;
        }
    }
    
    bfs(0,0);
    cout << dist[n-1][m-1];
    return 0;
}