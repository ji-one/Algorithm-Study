// 1915 가장 큰 정사각형

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n,m;
int arr[1001][1001];
int dp[1001][1001];

int main(){
    cin >> n >> m;
    int rst = 0;
    for(int i=0; i<n; i++){
        string s;
        cin >>s;
        
        for(int j=0; j<m;j++){
            arr[i][j] = s[j]-'0';
            if(arr[i][j] == 1)
                rst = 1;
        }
    }

    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = arr[i][j];
        }
    }

    
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            
            if(arr[i][j] == 1 && arr[i-1][j-1] == 1 && arr[i][j-1] == 1 && arr[i-1][j] == 1){
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j] ,dp[i][j-1]));
                rst = max(rst, dp[i][j]);
            }

        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d", rst*rst);
    return 0;
}