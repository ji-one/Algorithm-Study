// 1309 동물원
#include <iostream>

using namespace std;

int dp[100001];
int n;
int main(){
    cin >> n;
    dp[1] = 2;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + (dp[i-2]+dp[i-1] +2);
        dp[i]%=9901;
    }
    cout << dp[n]+1;
    return 0;
}

// ---------------------------------------
//  솔루션 봄
// #include <iostream>

// using namespace std;

// int dp[100001][3];  a번째 줄에서 b번에 사자를 배치하는 경우
//     [a][0] : 사자 x  [a][1] : 사자 왼쪽  [a][2] : 사자 오른쪽
// int n;
// int main(){
//     cin >> n;
//     dp[1][0] = dp[1][1] = dp[1][2] = 1;
//     for(int i=2; i<=n; i++){
//         dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
//         dp[i][1] = (dp[i-1][0] + dp[i-1][2])% 9901;
//         dp[i][2] = (dp[i-1][0] + dp[i-1][1])% 9901;
//     }
//     cout << (dp[n][0] + dp[n][1] + dp[n][2])% 9901;
//     return 0;
// }