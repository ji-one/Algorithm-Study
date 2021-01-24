// 1912 ¿¬¼ÓÇÕ 
#include <iostream>

using namespace std;

int n;
long long num[100001];
long long dp[100001];
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	
	dp[0] = num[0];
	for(int i=1; i<n; i++){
		if(dp[i-1]+num[i] > num[i])
			dp[i] = dp[i-1]+num[i];
		else{
			dp[i] = num[i];
		}
	}
	int rst = (-1001);
	for(int i=0; i<n; i++){
		if(rst < dp[i])
			rst = dp[i];
	}
	cout << rst;
	return 0;
}
