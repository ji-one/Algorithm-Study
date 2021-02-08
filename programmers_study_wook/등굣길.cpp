#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int map[101][101];
int visit[101][101];
int dx[] = {1,0};
int dy[] = {0,1};

bool isInside(int x, int y, int n, int m){
    return x>=0 && y>=0 && x<n && y<m;
}

int dfs(int x, int y, int n, int m){
    if(x == n-1 && y == m-1) return 1;
    if(map[x][y] != -1) return map[x][y];
    map[x][y] = 0;
    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isInside(nx,ny,n,m)  && map[nx][ny] != -2){
            map[x][y] += dfs(nx, ny,n,m);
            map[x][y]%=1000000007;
        }
    }
    
    return map[x][y]%1000000007;
}
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    memset(map, -1, sizeof(map));
    // 물 잠긴지역 표시
    for(int i=0; i<puddles.size(); i++){
        int wx = puddles[i][1]-1;
        int wy = puddles[i][0]-1;
        map[wx][wy] = -2;
    }
    
    answer = dfs(0,0,n,m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    return answer;
}
