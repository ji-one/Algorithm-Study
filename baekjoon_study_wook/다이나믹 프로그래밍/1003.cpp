// 1003 피보나치 함수
#include <iostream>

using namespace std;

//     0 1 개수 
// 0 : 1 0
// 1 : 0 1
// 2 : 1 1
// 3 : 1 2
// 4 : 2 3
int dp[41][2]; 
int t,n;

void fibo(){
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	
	for(int i=2; i<41; i++){
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}
}

int main(){
	cin>>t;
	fibo();
	while(t--){
		cin >> n;
		cout << dp[n][0] << ' ' << dp[n][1] << '\n';
	}
	return 0;
} 
