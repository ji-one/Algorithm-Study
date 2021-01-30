//9252  LCS 2

#include <iostream>

using namespace std;

int arr[1001][1001];
string a;
string b;
int main(){
	cin >> a>> b;
	int n = b.size();
	int m = a.size();
	for(int i=1; i<=b.size(); i++){
		for(int j=1; j<=a.size(); j++){
			if(b[i-1] == a[j-1]){
				arr[i][j] = arr[i-1][j-1]+1;
			}
			else{
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
			}
		}
	}
	
//	for(int i=0; i<=n; i++){
//		for(int j=0; j<=m ; j++){
//			cout << arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	cout << arr[n][m] << '\n';
	
	string s ="";
	int cnt = arr[n][m];
	for(int i=n; i>0; i--){
		for(int j=m; j>0; j--){
			int tmp = arr[i][j];
			if(cnt == arr[i][j] &&arr[i-1][j] == tmp-1 && arr[i][j-1] == tmp-1){
				s = b[i-1] + s;
				cnt--;
				break;
			}
		}
	}
	cout << s <<'\n';
	return 0;
}
