// 1780 종이의 개수 
#include <iostream>

using namespace std;

int arr[2200][2200];
int num[3] ={0,0,0}; // -1, 0, 1 각각의 개수

bool isSame(int x, int y, int c){
	int tmp = arr[x][y];
	for(int i=x; i<c+x; i++){
		for(int j=y; j<c+y; j++){
			if(arr[i][j] != tmp)
				return false;
		}
	}
	return true;
}

void solve(int x, int y, int c){
	
	if(isSame(x,y,c)){
//		cout << 1 << ' ';
		if(arr[x][y] == 1)
			num[2]++;
		if(arr[x][y] == 0)
			num[1]++;
		if(arr[x][y] == -1)
			num[0]++;
		return;
	}
	else{
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++)
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
			cin >> arr[i][j];
		}
	}
	
	solve(0,0,n);
	
	for(int i=0; i<3; i++){
		cout << num[i] << '\n';
	}
	return 0;
}
