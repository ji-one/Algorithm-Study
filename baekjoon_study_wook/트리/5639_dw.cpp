// 5639 이진 검색 트리 
#include <iostream>

using namespace std;

struct Tree{
	int left = 0;
	int right = 0;
};

Tree tree[100001];

void postOrder(int node){
	if(tree[node].left != 0){
		postOrder(tree[node].left);
	}
	if(tree[node].right != 0){
		postOrder(tree[node].right);
	}
	cout << node << '\n';
}
int main(){
	int root;
	int value;
	cin >> root;
	while(cin >>value){
		int node = root;
		while(1){
			if(node>value){
				if(tree[node].left !=0){
					node = tree[node].left;
				}
				else{
					tree[node].left = value;
					break;
				}
			}
			else{
				if(tree[node].right !=0){
					node = tree[node].right;
				}
				else{
					tree[node].right = value;
					break;
				}
			}
		}
	}
	
	postOrder(root);
	
	return 0;
}
