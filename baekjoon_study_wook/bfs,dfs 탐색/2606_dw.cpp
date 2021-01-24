//2606 바이러스
#include <iostream>
#include <queue>
using namespace std;

int n, k, rst;
int arr[101][101];
int visit[101];

void bfs(int v){
	visit[v] = 1;
	queue<int> q;
	q.push(v);
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=1; i<=n; i++){
			if(arr[x][i] == 1 && visit[i] ==0){
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=k; i++){
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
	}
	
	bfs(1);
	
	for(int i=2 ; i<=n ;i++){
		if(visit[i] == 1) rst++;
	}
	cout << rst;
	return 0;
} 
