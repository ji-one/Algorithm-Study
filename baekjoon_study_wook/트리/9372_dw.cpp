//9372 상근이의 여행 
#include <iostream>

using namespace std;

int t, n, m;
int arr[1001][1001];

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=0; i<m; i++){
			int a,b;
			cin >> a >> b;
			arr[a][b] = 1;
			arr[b][a] = 1;
		}
		cout << n-1 << '\n';
	}
	return 0;
}

