// 2573 빙산
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n,m;
int map[301][301];
int visit[301][301];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    visit[x][y] = 1;
    vector<pair<pair<int,int>, int>> v; // 좌표, 바다 개수
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        int cnt=0;
        // 동서남북 바다 개수 세기
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && map[nx][ny]==0){
                cnt++;
            }
        }
        v.push_back({{cx,cy}, cnt});

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && map[nx][ny]>0 && !visit[nx][ny]){
                q.push({nx,ny});
                visit[nx][ny] = 1;
            }
        }
    }

    // 녹이기
    for(int i=0; i<v.size(); i++){
        int cx = v[i].first.first;
        int cy = v[i].first.second;
        int cnt = v[i].second;
        map[cx][cy] -= cnt;
        if(map[cx][cy] < 0) map[cx][cy] = 0;
    }

}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    int t = 0;
    bool f;
    while(1){
        memset(visit, 0, sizeof(visit));
        int ice=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visit[i][j] && map[i][j]>0){
                    ice++; // 빙산 개수 증가
                    bfs(i,j);
                }
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << map[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << ice << '\n';
        if(ice>1) {
            f = true;
            break;
        }
        if(ice==0) {
            f = false;
            break;
        }
        t++;
    }
    if(f) cout << t;
    else  cout << 0;
    return 0;
}