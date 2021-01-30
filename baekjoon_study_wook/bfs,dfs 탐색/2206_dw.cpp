// 2206 벽 부수고 이동하기 -- 솔루션 봄
/*
1. 다음 칸이 벽이고, 벽을 이미 부순 경우
2. 다음 칸이 벽이고, 벽을 아직 부수지 않은 경우
3. 다음 칸이 빈칸이고, 이미 벽을 부순 경우
4. 다음 칸이 빈칸이고, 아직 벽을 부수지 않은 경우
*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;
int map[1001][1001];
// visit[x][y][z] (x,y)에 1: 벽을 부수고 방문 했는지, 0:부수지 않고 방문했는지 확인
int visit[1001][1001][2];  

void bfs(int x, int y){
    queue<pair<pair<int , int>, int>> q; // (x,y)(벽 부순 횟수)
    q.push({{x,y}, 0});
    visit[x][y][0] = 1;

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int b = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(map[nx][ny] == 0){
                   if(visit[nx][ny][b] == 0){
                       visit[nx][ny][b] = visit[cx][cy][b] + 1;
                       q.push({{nx,ny},b});
                   }
                
                }
                if(map[nx][ny] == 1){
                    if(!b &&visit[nx][ny][!b] == 0){
                        visit[nx][ny][!b] = visit[cx][cy][b] + 1;
                       q.push({{nx,ny},b+1});
                    }
                }

            }
        }
    }

    return ;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j] - '0';
        }
    }
    bfs(0,0);
    if(visit[n-1][m-1][0] == 0 && visit[n-1][m-1][1] == 0) 
        cout << -1;
    else{
        if(visit[n-1][m-1][0] == 0)
            cout << visit[n-1][m-1][1];
        else if(visit[n-1][m-1][1] == 0)
            cout << visit[n-1][m-1][0];
        else{
            cout <<min(visit[n-1][m-1][1], visit[n-1][m-1][0]);
        }
    }
        
    // cout << '\n';
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << visit[i][j][0] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << visit[i][j][1] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}