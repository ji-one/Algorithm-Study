// 11726 2xn 타일링 
#include <iostream>

using namespace std;

// 1 : 1  | 
// 2 : 2  ||   =
// 3 : 3  |||  |=  =|
// 4 :    | +  ||| 개수 ,  = +  || 개수 

int dp[1001];
int n;
int main(){
	cin>>n;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=n; i++){
		dp[i] = (dp[i-1] + dp[i-2])%10007;
	}
	cout << dp[n];
	return 0;
} 
