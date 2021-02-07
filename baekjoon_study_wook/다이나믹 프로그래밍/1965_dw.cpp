// 1965 상자넣기

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int box[1001];
int dp[1001];
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> box[i];
    }

    int rst = 0;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(box[i] > box[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        rst = max(rst, dp[i]);
    }

    cout << rst;
    return 0;
}