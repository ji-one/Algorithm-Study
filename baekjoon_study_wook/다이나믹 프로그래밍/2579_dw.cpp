// 2579 ��� ������ 
#include <iostream>

using namespace std;

//  i - 2 ������ ���� + �� ĭ ���� i ����
//  i - 3 ������ ���� + (�� ĭ �ٰ�) + i - 1 ���� + i ���� 

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
