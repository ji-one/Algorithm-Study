//11047 ���� 0
#include <iostream>
using namespace std;

int n, k, rst;
int arr[10]; // ������ ��ġ 
int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	while(n--|| k != 0){
		if(k>=arr[n]){
			rst += (k/arr[n]);
			k = k%arr[n];
		}
	}
	cout << rst;
	return 0;
} 
