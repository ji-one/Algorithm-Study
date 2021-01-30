// LCS 9251
#include <iostream>
#include <algorithm>

using namespace std;

string a;
string b;

int arr[1001][1001];

int main(){
	cin >> a >> b;
	
	for(int i=1; i<=b.size(); i++){
		for(int j=1; j<=a.size(); j++){
			if(b[i-1] == a[j-1]){
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else{
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
			}
		}
	}
	cout << arr[b.size()][a.size()] << '\n';
	return 0;
}
