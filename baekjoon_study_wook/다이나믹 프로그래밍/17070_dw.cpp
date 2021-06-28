// 17070 파이프 옮기기 1

#include <iostream>
#include <queue>

using namespace std;
int n;
int house[20][20];
int visit[20][20][3];   // x y좌표, 방향

bool isInside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

// 좌표 , 파이프 놓여진 방향 -- 0 : 가로 | 1 : 세로 | 2 : 대각선
int dfs(int x, int y, int d) {
    if(visit[x][y][d] != -1) return visit[x][y][d];
    
    if(x==n-1 && y==n-1) {
        return 1;
    }

    visit[x][y][d] = 0;
    if(d == 0) {
        if(isInside(x,y+1) && house[x][y+1] == 0) { // 빈칸이면
            visit[x][y][d] += dfs(x, y+1, 0);
        }

        if(isInside(x+1, y+1) && house[x][y+1] == 0 
        && house[x+1][y+1] == 0 && house[x+1][y] == 0) {
            visit[x][y][d] += dfs(x+1, y+1, 2);
        }
    }

    if(d == 1) {
        if(isInside(x+1,y) && house[x+1][y] == 0) {
            visit[x][y][d] += dfs(x+1, y, 1);
        }

        if(isInside(x+1, y+1) && house[x][y+1] == 0 
        && house[x+1][y+1] == 0 && house[x+1][y] == 0) {
            visit[x][y][d] += dfs(x+1, y+1, 2);
        }
    }

    if(d == 2) {
        if(isInside(x,y+1) && house[x][y+1] == 0) {
            visit[x][y][d] += dfs(x, y+1, 0);
        }

        if(isInside(x+1,y) && house[x+1][y] == 0) {
            visit[x][y][d] += dfs(x+1, y, 1);
        }

        if(isInside(x+1, y+1) && house[x][y+1] == 0 
        && house[x+1][y+1] == 0 && house[x+1][y] == 0) {
            visit[x][y][d] += dfs(x+1, y+1, 2);
        }
    }

    return visit[x][y][d];
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> house[i][j];
        }
    }
    fill(&visit[0][0][0], &visit[n-1][n-1][3], -1);
    
    cout << dfs(0,1, 0) <<'\n';

    // for(int i=0 ; i<3; i++) {
    //     for(int j=0; j<n; j++) {
    //         for(int k=0; k<n; k++) {
    //             cout << visit[j][k][i] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }
    return 0;
}