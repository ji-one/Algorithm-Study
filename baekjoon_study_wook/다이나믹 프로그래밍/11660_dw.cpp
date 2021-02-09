// 11660 구간합 구하기 5
#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int map[1111][1111];
int dp[1111][1111];
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
            
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1)
                dp[i][j] = dp[i][j-1] + map[i][j];
            else if(j == 1)
                dp[i][j] = dp[i-1][j] + map[i][j];
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
                            -dp[i-1][j-1] + map[i][j];
            }
            
        }
    }
    
    for(int i=0; i<m; i++){

        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int sum= dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]; 

        cout << sum << '\n';

    }
    return 0;
}