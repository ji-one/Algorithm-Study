#include <iostream>
#include <vector>
using namespace std;

int n,k;
int arr[201];
int main(){
	cin >> n >> k;
	for(int i=1; i<=2*n; i++){
		cin >> arr[i];
	}
	int step=0;
	vector<int> v(2*n+1,0);   // v[i] = i위치에 로봇 잇음   
	while(1){
		
//		for(int i=1; i<=2*n; i++){
//			cout << arr[i] << ' ';
//		}
//		cout << "-------";
//		for(int i=1; i<=2*n; i++){
//			if(v[i]>0){
//				cout << "로봇 위치 : " <<i << ' ';
//			}
//		}
//		cout << '\n';
		int cnt=0;
		for(int i=1; i<=2*n; i++){
			if(arr[i] == 0)
				cnt++;
		}
		if(cnt >= k) break;
		
		
		// 1.
		int tmp1 = arr[2*n];
		int tmp2 = v[2*n];
		
		for(int i=2*n; i>1; i--){
			arr[i] = arr[i-1];
			v[i] = v[i-1];

		}
		arr[1] = tmp1;
		v[1] = tmp2;
		
		if(v[n]==1){
			v[n] = 0;
		}
		// 2.
		for(int i=n; i>1; i--){
			if(v[i-1] > 0 && arr[i] >0 && v[i] == 0){  // i-1위치에 로봇이 있고, i 내구도가 1이상이면 
				v[i] = v[i-1];
				v[i-1] = 0;
				arr[i]--;
			}
			if(v[n]==1){
				v[n] = 0;
			}
		}
		
		// 3.
		if(arr[1] != 0){
			arr[1]--;
			v[1] = 1; 
		}
		
		step++;
	}
	
	cout << step;
	return 0;
}
