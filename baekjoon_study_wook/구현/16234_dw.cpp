// 16234 인구 이동
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n,l,r;
int map[51][51];
int visit[51][51];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

vector<pair<int,int>> v; // 연합 좌표 정보 저장

bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    visit[x][y] = 1;

    v.push_back({x,y});
    int sum = map[x][y];
    int cnt = 1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int dif = abs(map[cx][cy] - map[nx][ny]);
            if(isInside(nx,ny) && !visit[nx][ny] && l<=dif && dif<=r){
                q.push({nx,ny});
                visit[nx][ny] = 1;
                v.push_back({nx,ny});
                sum += map[nx][ny];
                cnt++;

            }
        }
    }

    // 인구 이동
    int avg = sum/cnt;
    for(int i=0; i<v.size(); i++){
        int a = v[i].first;
        int b = v[i].second;
        map[a][b] = avg;
    }
    v.clear();
}
int main(){
    int rst = 0;
    cin >> n >> l >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    
    while(1){
        memset(visit,0,sizeof(visit));

        bool exit = true;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // 연합할 수 있는지 확인
                if(visit[i][j]) continue;
                for(int k=0; k<4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    int dif = abs(map[i][j] - map[nx][ny]);
                    if(isInside(nx,ny) && !visit[i][j] && l<=dif && dif<=r){
                        bfs(i,j);
                        exit = false;
                    }
                }
                
            }
        }
        
        // 인구 이동이 없으면 종료
        if(exit) break; 
        // cout << '\n';
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << map[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        rst++;
    }
    cout << rst;
    return 0;
}