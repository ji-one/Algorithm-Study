//2630 색종이 만들기
#include <iostream>
using namespace std;

int arr[1000][1000];
int num[2]; // 하얀색 파란색
 
bool isSame(int x, int y, int c){
	int tmp = arr[x][y];
	for(int i=x; i<c+x; i++){
		for(int j=y; j<c+y; j++){
			if(tmp != arr[i][j])
				return false;
		}
	}
	return true;
}
void solve(int x, int y, int c){
	
	if(isSame(x,y,c)){
		if(arr[x][y] == 1)
			num[1]++;
		if(arr[x][y] == 0)
			num[0]++;
		return ;
	}
	else{
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				solve(x+(i*c/2),y+(j*c/2),c/2);
			}
		}
	}
	
	return ;
}
int main(){
	int n;
	cin >>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	
	solve(0,0,n);
	
	for(int i=0; i<2; i++){
		cout << num[i] << '\n';
	}
	return 0;
} 
