// 17425 약수의 합 -- 솔루션

#include<iostream>
#define MAX 1000000
using namespace std;

long long arr[MAX+1];
long long dp[MAX+1];
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n, t;
    cin >> t;
    fill(dp, dp+MAX+1, 1); // 모든 숫자가 약수 1을 가지므로

    // n=ab 일때 a 가 n의 약수 인 것을 이용
    for(int i=2; i<=MAX; i++) {
        for(int j=1; i*j<=MAX; j++) {
            dp[i*j] += i;            
        }
    }
    // 약수들의 합을 미리 더해준다.
    for(int i=1; i<=MAX; i++) {
        arr[i] = arr[i-1] + dp[i];
    }
    while(t--) {
        cin >> n;
        cout << arr[n] << '\n';
    }
    
    return 0;
}