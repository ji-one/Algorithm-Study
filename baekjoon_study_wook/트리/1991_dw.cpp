// 1991 트리 순회  
#include <iostream>

using namespace std;

int n;
char tree[27][2];  // 부모 왼자식 오른자식

void preorder(int n){
	char node = n +'A';
	cout << node;
	
	for(int i=0; i<2;i++){
		if(tree[n][i]!= '.')
			preorder(tree[n][i] - 'A');
	}
}

void inorder(int n){
	
	if(tree[n][0]!= '.')
		inorder(tree[n][0] - 'A');
		
	char node = n +'A';
	cout << node;
	
	if(tree[n][1]!= '.')
		inorder(tree[n][1] - 'A');
	
	return ;
}

void postorder(int n){
	
	for(int i=0; i<2;i++){
		if(tree[n][i]!= '.')
			postorder(tree[n][i] - 'A');
	}
	char node = n +'A';
	cout << node;
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		char al;
		cin >> al;
		for(int j=0; j<2; j++){
			cin >> tree[al - 'A'][j];
		}
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	return 0;
} 
