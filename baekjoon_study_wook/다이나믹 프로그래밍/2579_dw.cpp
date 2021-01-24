// 2579 계단 오르기 
#include <iostream>

using namespace std;

//  i - 2 개까지 점수 + 두 칸 넘은 i 점수
//  i - 3 개까지 점수 + (두 칸 뛰고) + i - 1 점수 + i 점수 

int dp[301];
int ans[301];
int n;
int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin >> dp[i];
	} 
	ans[1] = dp[1];
	ans[2] = dp[2] + dp[1];
	for(int i=3 ; i<=n; i++){
		ans[i] = max(ans[i-2] + dp[i], ans[i-3] + dp[i-1] + dp[i]);
	}
	cout << ans[n];
	return 0;
} 
