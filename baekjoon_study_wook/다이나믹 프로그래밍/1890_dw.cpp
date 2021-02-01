// 1890 점프
#include <iostream>

using namespace std;

int n;
int map[101][101];
long long dp[101][101];

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==n-1 && j == n-1) continue;

            if(dp[i][j]>0){
                dp[i+map[i][j]][j]+= dp[i][j];
                dp[i][j+map[i][j]]+= dp[i][j];
            }
            
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n-1][n-1];
    return 0;
}