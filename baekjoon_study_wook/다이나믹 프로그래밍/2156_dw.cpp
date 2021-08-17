// 2156 포도주 시식

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int podo[10001];
int dp[10001];

int main() {
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> podo[i];
    }
    dp[1] = podo[1];
    dp[2] = dp[1] + podo[2];

    for(int i=3; i<=n; i++) {
        dp[i] = max(dp[i-1], max(dp[i-2], dp[i-3] + podo[i-1]) + podo[i]);
    }

    // for(int i=1; i<=n; i++) {
    //     cout << dp[i] << ' ';
    // }
    cout << dp[n];
    return 0;
}