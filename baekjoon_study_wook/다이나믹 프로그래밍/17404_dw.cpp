// 17404 RGB거리 2

#include <iostream>
#include <algorithm>
#define MAX 987654321

using namespace std;

int n;
int rgb[1001][3];
int dp[1001][3];

int main() {
    cin >> n;
    int answer = MAX;
    for(int i=0; i<n; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    for(int color=0; color<3; color++) {
        for(int i=0; i<3; i++) {
            if(i == color) {
                dp[0][i] = rgb[0][i];
            } else {
                dp[0][i] = MAX;
            }
        }
        
        for(int i=1; i<n; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
        }

        for(int i=0; i<3; i++) {
            if(i == color) continue;
            answer = min(answer, dp[n-1][i]);
        }
    }
    cout << answer;
    return 0;
}