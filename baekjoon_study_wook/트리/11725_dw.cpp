// 11725 트리의 부모 찾기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> v[100001];
int visit[100001];
int parent[100001];

void dfs(int node){
	visit[node] = 1;
	
	for(int i=0; i<v[node].size(); i++){
		if(!visit[v[node][i]]){
			parent[v[node][i]] = node;
			dfs(v[node][i]);
		}
	}
}

void bfs(int node){
	visit[node] = 1;
	queue<int> q;
	q.push(node);
	
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i=0; i<v[tmp].size(); i++){
			int nv = v[tmp][i];
			if(!visit[nv]){
				visit[nv] = 1;
				parent[nv] = tmp;
				q.push(nv);
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i=1; i<n; i++){
		int v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	
//	dfs(1);
	bfs(1);
	for(int i=2; i<=n; i++){
		cout << parent[i] <<'\n';
	}
	return 0;
}
