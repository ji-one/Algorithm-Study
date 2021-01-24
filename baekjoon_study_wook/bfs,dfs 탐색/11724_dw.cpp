// 11724 연결 요소의 개수 
 
#include <iostream>
#include <queue>

using namespace std;

int n,m, rst;
int graph[1001][1001];
int visit[1001];

void bfs(int v){
	visit[v] = 1;
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=1; i<=n; i++){
			if(!visit[i] && graph[x][i]){
				q.push(i);
				visit[i] =1;
			}
		}
	}
}
int main(){
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int from, to;
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}
	
	for(int i=1; i<=n; i++){
		if(!visit[i]){
			bfs(i);
			rst++;
		}
	}
	
	cout << rst;
	return 0;
}
