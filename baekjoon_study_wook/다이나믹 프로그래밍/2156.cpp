// 2156 포도주 시 식 
#include <iostream>

using namespace std;
// 999  999  1  1  999   999
int n;
int jan[10001];
int dp[10001];
int main(){
	cin >> n;
	
	for(int i=1; i<=n;i++){
		cin >> jan[i];
	}
	dp[1] = jan[1];
	dp[2] = jan[1] + jan[2];
	dp[3] = max(dp[1] + jan[3], jan[2] + jan[3]);
	for(int i=4;i<=n; i++){
		dp[i] = max(dp[i-2] + jan[i], max(dp[i-3]+ jan[i-1] + jan[i], dp[i-4] + jan[i-1] + jan[i]));
	}
	int rst = 0;
	for(int i=1; i<=n; i++){
		if(rst < dp[i]){
			rst = dp[i];
		}
	}
	cout << rst << '\n';
	return 0;
}
