//10942 �Ӹ����?  --- �ַ�� ��  
#include <iostream>

using namespace std;

int n,m, s,e;
int arr[2001];
int dp[2001][2001];

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}
//	���̰� 1�� ��� (���ڸ�) 
	for(int i=1; i<=n ; i++){
		dp[i][i] = 1;
	}
//	���̰� 2�� ��� (���ڸ� ���� ��) 
	for(int i=1; i<n; i++){
		if(arr[i] == arr[i+1]){
			dp[i][i+1] = 1;
		}
	}
//	���̰� 3�̻��� ���
	for(int i=2; i<n; i++){	// ������ �Ÿ�  
		for(int j=1; j<=n-i; j++){ 
			
			if(arr[j] == arr[j+i] && dp[j+1][j+i-1] == 1){
				dp[j][j+i] = 1;
			}
		}
	} 
	scanf("%d",&m);
	while(m--){
		scanf("%d %d", &s, &e);
		printf("%d\n",dp[s][e]);
	}
	return 0;
}
