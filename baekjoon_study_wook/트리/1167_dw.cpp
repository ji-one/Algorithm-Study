//1167 트리의 지름   
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<pair<int, int>> tree[100001];
int visit[100001];

int rst;
int end_point;

void dfs(int node, int len){
	if(visit[node]) return ;
	visit[node] = 1;
	if(rst < len){
		rst = len;
		end_point = node;
	}
	
	for(int i=0; i<tree[node].size(); i++){
		dfs(tree[node][i].first, len + tree[node][i].second);
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int parent;
		cin >> parent;
		while(1){
			int child, edge;
			cin >> child;
			if(child == -1) break;
			cin >> edge;
			
			tree[parent].push_back({child,edge});
			tree[child].push_back({parent,edge});
		}
	}
	
	dfs(1,0);
	
	memset(visit, 0, sizeof(visit));
	
	rst = 0;
	dfs(end_point, 0);
	
	cout << rst ;
	return 0;
} 
