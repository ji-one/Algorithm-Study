//11967 불켜기
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
int map[101][101];  // 불켜진 방 확인
int visit[101][101];
vector<pair<int, int>> swit[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

bool isInside(int x, int y){
    return x>=1 && x<=n && y>=1 && y<=n;
}

bool bfs(){
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>>  q;
    q.push({1,1});
    map[1][1] = 1;
    bool flag = false; // 켜는 불이 있는 지 확인
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 불켜기
        for(int i=0; i<swit[cx][cy].size(); i++){
            int a = swit[cx][cy][i].first;
            int b = swit[cx][cy][i].second;
            if(!map[a][b]){
                map[a][b] = 1;
                flag = true;
            }
        }
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && map[nx][ny] == 1 && !visit[nx][ny]){
                q.push({nx,ny});
                visit[nx][ny] = 1;
            }
        }
    }

    return flag;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        swit[x][y].push_back({a,b});
    }
    while(1){
        if(!bfs()) break;

    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j] == 1){
                cnt++;
            }
        }
    }


    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << cnt;

    return 0;
}