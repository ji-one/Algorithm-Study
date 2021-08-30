// 2631 줄세우기

#include <iostream>

using namespace std;

int n;
int arr[222];
int dp[222];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j] && dp[i] < dp[j] +1) {
                dp[i] = dp[j] + 1;
            }
        }
        if(ans < dp[i]) {
            ans = dp[i];
        }
    }

    cout << n - ans;
    return 0;
}