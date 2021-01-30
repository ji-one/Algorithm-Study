// 2225 합분해

#include <iostream>
#include <vector>
using namespace std;

int n,k;
long long dp[201][201]; 
// dp[i][j] : i개를 더해서 합이 j인 경우의 수

int main(){
    cin >> n >> k;
    for(int i=0; i<=n; i++){
        dp[1][i] = 1;
    }
    for(int i=2; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int k = 0; k<=j; k++){
                dp[i][j] += dp[i-1][j-k];
                dp[i][j]%=1000000000LL;
            }
            
        }
    }

    cout << dp[k][n];
    return 0;
}