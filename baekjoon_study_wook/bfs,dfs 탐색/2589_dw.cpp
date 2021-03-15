// 2589 보물섬
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
char s[51][51];
int visit[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(int x, int y){
    visit[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x,y});
    int d = 0;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(d < visit[cx][cy]){
            d = visit[cx][cy];
        }

        for(int i=0; i<4; i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(isInside(nx,ny) && s[nx][ny] == 'L' && !visit[nx][ny]){
                q.push({nx,ny});
                visit[nx][ny] = visit[cx][cy] + 1;
            }
        }
    }
    return d-1;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> s[i][j];
        }
    }

    int dist = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j] == 'L'){
                memset(visit, 0, sizeof(visit));
                dist = max(dist, bfs(i,j));
                // cout << dist << '\n';
            }
        }
    }

    cout << dist;
    return 0;
}