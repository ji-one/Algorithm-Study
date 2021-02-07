// 3055 탈출

#include <iostream>
#include <queue>
using namespace std;

int r,c;
char map[51][51]; // . 빈곳,  * 물,  X 돌,  D 비버,  S 고슴도치
int visit[51][51];
int water[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool isInside(int x, int y){
    return x>=0 && x<r && y>=0 && y<c;
}
queue<pair<int,pair<int, int>>> q1;
queue<pair<int, int>> q2;
void flooding(){

    while(!q2.empty()){
        int cx = q2.front().first;
        int cy = q2.front().second;
        
        // int ct = q2.front().first;
        q2.pop();
        for(int i=0; i<4; i++){
            int nx = cx +dx[i];
            int ny = cy +dy[i];
            if(isInside(nx, ny) && !water[nx][ny] && map[nx][ny] == '.'){
                water[nx][ny] = water[cx][cy] + 1;
                q2.push({nx,ny});
            }
        }
    }
}

bool move(){

    while(!q1.empty()){
        int cx = q1.front().second.first;
        int cy = q1.front().second.second;
        int ct = q1.front().first;
        if(map[cx][cy] == 'D'){
            return true;
        }
        q1.pop();

        for(int i=0; i<4; i++){
            int nx = cx +dx[i];
            int ny = cy +dy[i];
            int nt = ct + 1;
            if(isInside(nx, ny) && !visit[nx][ny] && map[nx][ny] != 'X'
                && (water[nx][ny]-1 > nt || water[nx][ny]==0)){
                visit[nx][ny] = nt;
                q1.push({nt, {nx,ny}});
            }
        }
    }

    return false;
}

int main(){

    cin >> r >> c;
    int x, y;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
            if(map[i][j] == 'S'){
                q1.push({0,{i,j}});
                visit[i][j] = 1;
            }
            if(map[i][j] == '*'){
                q2.push({i,j});
                water[i][j] = 1;
            }
            if(map[i][j] == 'D'){
                x = i;
                y = j;
            }
        }
    }
    flooding();

    if(move()) cout << visit[x][y];
    else        cout << "KAKTUS";

    cout << '\n';
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << water[i][j] << ' ';
        }
        cout << '\n';

    }
    return 0;
}