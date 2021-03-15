// 카드 구매하기 2
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int p[10001];
int dp[10001]; // dp[i]는 i개 살때 최소값
int main(){
    cin >> n;
    fill(dp, dp+n+1, 10000000);
    for(int i=1; i<=n; i++){
        cin >> p[i]; 
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i/2; j++){
            dp[i] = min(dp[i], p[j] + p[i-j]);
        }
        p[i] = dp[i];
    }
    for(int i=1; i<=n; i++){
        cout << dp[i] << ' ';
    }
    cout << dp[n];
    return 0;
}