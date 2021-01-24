// 1080 За·Д 
#include <iostream>

using namespace std;

int n,m;
int A[51][51];
int B[51][51];

void cal(int x, int y){
	for(int i=x; i<x+3; i++){
		for(int j=y; j<y+3; j++){
			A[i][j] = 1 - A[i][j];
		}
	}
}
bool cmp(){
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if(A[i][j] != B[i][j])
				return false;
		}
	}
	return true;
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<m; j++){
			A[i][j] = s[j] - '0';
		}
	}
	
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<m; j++){
			B[i][j] = s[j] - '0';
		}
	}
	int ans=0;
	for(int i=0; i<n-2; i++){
		for(int j=0; j<m-2; j++){
			if(A[i][j] != B[i][j]){
				cal(i,j);
				ans++;
			}
		}
	}
	if(cmp()){
		cout << ans;
	}
	else{
		cout << -1;
	}
	return 0;
}
