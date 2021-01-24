// 9663 N-Queen  �ַ�� �� 
#include<iostream>
#include <vector>
using namespace std;

int n, rst;
int col[16]; // �� ������ ��ġ�� ��  
			// col[1] = 2  1�� 2�� (1,2) ��ġ 

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
