// 1937 욕심쟁이 판다

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int Bamboo[501][501];
int dp[501][501];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int ans;
int dfs(int x, int y){
    
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y]=1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(Bamboo[x][y] < Bamboo[nx][ny]){
                dp[x][y] = max(dp[x][y], dfs(nx,ny)+1) ;
            }
        }
    }
    return dp[x][y];
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> Bamboo[i][j];
            dp[i][j] = -1;
        }
    }
    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans,dfs(i,j));
        }
    }

    cout << ans;

    return 0;
}