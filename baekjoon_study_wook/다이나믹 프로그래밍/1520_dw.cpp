// 1520 내리막 길
/*
dfs로 풀었더니 시간초과 => 최악의 경우 4^(500*500) 탐색 필요
솔루션 봄
DFS + DP 를 이용해 메모이제션으로 시간을 줄여줌

*/
#include <iostream>

using namespace std;

int n,m;
int map[501][501];
// dp[a][b]=c (a,b)에서 (n-1,m-1)까지 c개의 경로로 도달할 수 있다.
int dp[501][501] ;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int dfs(int x, int y){
    if(x==n-1 && y==m-1){
        return 1;
    }

    // 이미 탐색한 경로이므로 해당 좌표부터 도착까지 경로를 반환
    if(dp[x][y] != -1) return dp[x][y];

    // 아직 탐색 하지 않았으므로 탐색
    dp[x][y] = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isInside(nx,ny)  && map[nx][ny] < map[x][y]){
            dp[x][y] = dp[x][y] + dfs(nx,ny);
        }
    }

    return dp[x][y];
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0,0) << '\n';

    return 0;
}