// 11727 2xn ≈∏¿œ∏µ 2 
#include <iostream>

using namespace std;

// 1 : |   1
// 2 : || = x  3
// 3 : |||    |=   =|   x|    |x  5
// 4 : ||||   ||=   |=|   =||   ||x   |x|   x||   x=  =x  == xx 11
int n;
int dp[1001];
int main(){
	cin >> n;
	
	dp[0] = 1;
	dp[1] = 3;
	for(int i=2; i<n; i++){
		dp[i] = (dp[i-1] + 2*dp[i-2])%10007;
	}
	cout << dp[n-1];
	return 0;
}
