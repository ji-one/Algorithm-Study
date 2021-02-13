// 17626 Four Squares
// 솔루션 봄
/*
    1 -> 1^2                dp[1] = 1
    2 -> 1^2 + 1^2          dp[2] = dp[1] + dp[2-1]
    3 -> 1^2 + 1^2 + 1^2    dp[3] = dp[1] + dp[3]
    4 -> 2^2                dp[4] = dp[4]
    5 -> 2^2 + 1            dp[5] = dp[4] + dp[5-1]
    ...
    n -> dp[i] = dp[j] + dp[i - j*j]
    j 는 루트 i 보다 클 수 없다
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int dp[50001];

int main(){
    cin >> n;
    fill(dp,dp+n+1,5);
    for(int i=1; i<=n; i++){
        if(i == (int)sqrt(i)*(int)sqrt(i))
            dp[i] = 1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(int)sqrt(i); j++){
            dp[i] = min(dp[i], dp[j*j] + dp[i - j*j]);
        }
    }
    cout << dp[n];
    return 0;
}