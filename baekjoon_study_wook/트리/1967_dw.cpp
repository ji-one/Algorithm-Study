//1967 트리의 지름     솔루션 - 봄 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<pair<int, int>> tree[10001];
vector<pair<int,int>> r;
int visit[10001];
int rst;
int endpoint;
void dfs(int root,int len){
	if(visit[root]){
		return;
	}
	
	visit[root]=1;
	
	if(rst<len){
		rst = len;
		endpoint = root;
	}
	
	for(int i=0; i<tree[root].size(); i++){
		dfs(tree[root][i].first, len+tree[root][i].second);	
	}
	return ;
}
int main(){
	cin >> n;
	for(int i=0; i<n-1; i++){
		int parent, child, edge;
		cin >> parent >> child >> edge;
		tree[parent].push_back({child, edge});
		tree[child].push_back({parent,edge}); // 끝지점에서 길이 알기 위해 필요  
	}
	
	dfs(1,0);
	memset(visit, 0, sizeof(visit));
	dfs(endpoint,0); // 다시 가장 먼 지점 찾기
	cout << rst; 
	return 0;
} 
