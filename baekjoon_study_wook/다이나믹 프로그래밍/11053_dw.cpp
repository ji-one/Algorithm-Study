// 11053 가장 긴 증가하는 부분 수열

#include <iostream>

using namespace std;
// 10 50 20 30 40
int n;
int num[1001];
int dp[1001];
int main(){
	cin >> n;
	for(int i=0;i<n; i++){
		cin >> num[i];
	}
	dp[0] = 1;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(num[i] > num[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
			
		}
		if(dp[i] == 0) dp[i] = 1;
	}
//	for(int i=0; i<n;i++){
//		cout << dp[i] << ' ';
//	}
	int rst = 0;
	for(int i=0; i<n; i++){
		if(rst < dp[i])
			rst = dp[i];
	}
	cout <<rst <<'\n';
	return 0;
}
