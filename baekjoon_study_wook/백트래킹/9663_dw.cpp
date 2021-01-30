// 9663 N-Queen  솔루션 봄 
#include<iostream>
#include <vector>
using namespace std;

int n, rst;
int col[16]; // 각 열에서 위치한 행  
			// col[1] = 2  1열 2행 (1,2) 위치 

bool isPromising(int level){
	for(int j=0; j<level; j++){
		if(col[j] == col[level] || (abs(col[level] - col[j]) == (level-j)))
			return false;
	}
	return true;
}
void dfs(int j){
	if(j==n){
		rst++;
		return ;
	}
	
	for(int i=0; i<n; i++){
		col[j] = i;
		if(isPromising(j)){
			dfs(j+1);
		}
	}

	
	
}
int main(){
	cin >>n;
	
	dfs(0);
	cout << rst << '\n';
	return 0;
} 
