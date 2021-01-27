// 11051 이항 계수 2
#include <iostream>

using namespace std;

int n,k;
int dp[1010][1010];
int main(){
    cin >> n >> k;
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j == 0) dp[i][j] = dp[i-1][j]%10007;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;
        }
    }

    cout << dp[n][k];
    return 0;
}