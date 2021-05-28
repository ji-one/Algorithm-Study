// 1261 알고스팟

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int m,n;
int map[101][101];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int visit[101][101];

bool isInside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs() {
    priority_queue<pair<int, pair<int,int>>> pq; // 벽개수, {x,y 좌표}
    pq.push({0, {0,0}});
    visit[0][0] = 1;

    while(!pq.empty()) {
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        int cb = -pq.top().first;
        pq.pop();

        if(n == cx+1 && m == cy+1) {
            cout << cb;
            return ;
        }
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(isInside(nx,ny)) {
                if(!visit[nx][ny] && map[nx][ny] == 0) {
                    visit[nx][ny] = visit[cx][cy];
                    pq.push({-cb, {nx,ny}});
                } else if(!visit[nx][ny] && map[nx][ny] == 1) {
                    visit[nx][ny] = visit[cx][cy] + 1;
                    pq.push({-(cb+1), {nx,ny}});
                } else if(visit[nx][ny] && map[nx][ny] == 0) {
                    if(visit[nx][ny] > visit[cx][cy]) {
                        visit[nx][ny] = visit[cx][cy];
                        pq.push({-cb, {nx,ny}});
                    }
                } else if(visit[nx][ny] && map[nx][ny] == 1) {
                    if(visit[nx][ny] > visit[cx][cy]+1) {
                        visit[nx][ny] = visit[cx][cy] + 1;
                        pq.push({-(cb+1), {nx,ny}});
                    }
                }
            }
        }
    }

    return ;
}
int main() {
    cin >> m >> n;
    
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    bfs();
    
    return 0;
}