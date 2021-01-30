// 2294 동전 2
#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int coin[101];
int dp[100001];
int main(){
    cin >> n >> k;
    fill(dp, dp+k+1, 10000001);
    for(int i=1; i<=n; i++){
        cin >> coin[i];
        dp[coin[i]] = 1;
    }
    
    for(int i=1; i<=k; i++){
        for(int j=1; j<=i/2; j++){
            dp[i] = min(dp[i], dp[i-j] + dp[j]);
        }
    }

    if(dp[k] == 10000001) cout <<-1;
    else    cout << dp[k];
    return 0;
}