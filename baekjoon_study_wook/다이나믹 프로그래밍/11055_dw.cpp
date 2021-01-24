// 11055 가장 큰 증가 부분 수열

#include <iostream>

using namespace std;

int n;
int num[1001];
int dp[1001];
int main(){
	cin >> n;
	for(int i=0;i<n; i++){
		cin >> num[i];
	}
	
	int rst = 0;
	for(int i=0; i<n; i++){

		for(int j=0; j<i; j++){
			if(num[i] > num[j]){
				dp[i] = max(dp[i], dp[j]);
			}
			
		}
		dp[i] +=num[i];
		rst = max(rst, dp[i]);
	}
//	for(int i=0; i<n;i++){
//		cout << dp[i] << ' ';
//	}
	
	cout <<rst <<'\n';
	return 0;
}
