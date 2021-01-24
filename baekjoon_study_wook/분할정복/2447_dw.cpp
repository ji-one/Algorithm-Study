// 2447 º° Âï±â - 10 
#include <iostream>
#include <cstring>
using namespace std;

char arr[2200][2200];

void solve(int x, int y, int c){
	
	if(c == 1){
		arr[x][y] = '*';
		return ;
	}
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i == 1 && j == 1) continue;
			solve(x+(i*c/3),y+(j*c/3),c/3);
			
		}
	}
	
	
	return ;
}

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			arr[i][j] = ' ';
		}
	}
	
	solve(0,0,n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << arr[i][j] ;
		}
		cout << '\n';
	}
	return 0;
}
