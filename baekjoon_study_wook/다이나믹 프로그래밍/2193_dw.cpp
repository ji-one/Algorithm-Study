// 2193 이친수 
#include <iostream>

using namespace std;

// 1 : 1
// 2 : 10
// 3 : 100 101
// 4 : 1000 1001 1010
// 5 : 10000 10010 10100 10101 10001
// i : 1 + i-1자리개수 , 10 + i-2자리개수 
int n;
long long dp[91];
int main(){
	cin >> n;

	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n] << '\n';
	return 0;
}
