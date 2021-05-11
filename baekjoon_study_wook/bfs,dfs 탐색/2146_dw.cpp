// 2146 다리 만들기
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int rst = 10001;
int map[101][101];
int visit[101][101];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void makeLandLabel(int x, int y, int L){
    queue<pair<int, int> > q;
    q.push({x,y});
    visit[x][y] = 1;
    map[x][y] = L;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0 ; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && !visit[nx][ny] && map[nx][ny] == -1){
                q.push({nx,ny});
                visit[nx][ny] = 1;
                map[nx][ny] = L;
            }
        }
    }
}

void bfs(int x, int y){
    int a = map[x][y];
    queue<pair<int, int> >q;
    q.push({x,y});
    visit[x][y] = 1;
    bool exit = false;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && !visit[nx][ny]){
                if(map[nx][ny] == 0){
                    q.push({nx,ny});
                    visit[nx][ny] = visit[cx][cy] + 1;
                }
                else if(map[nx][ny] != a){
                    exit = true;
                    rst = min(rst, visit[cx][cy] - 1);
                    break;
                }
            }
        }
        if(exit) break;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1)
                map[i][j] = -1;
        }
    }

    int num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == -1){
                num++;
                makeLandLabel(i,j,num);
            }
                
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fill(&visit[0][0], &visit[n-1][n], 0);
            if(map[i][j] != 0){
                bfs(i,j);
            }
        }
    }

    cout << rst;
    return 0;
}