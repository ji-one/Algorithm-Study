// 단지번호붙이기 2667 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int map[26][26];
int visit[26][26];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<int> v;

int cnt;

bool Isinside(int x, int y){
	return (x>=0 && x<n && y>=0 && y<n);
}
void dfs(int x, int y){
	visit[x][y] = 1;
	cnt++;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(Isinside(nx,ny) && map[nx][ny] == 1 && visit[nx][ny] == 0){
			dfs(nx,ny);
		}
	}
}

void bfs(int x, int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	visit[x][y] = 1;
	int cnt = 1;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(map[nx][ny] == 1 && visit[nx][ny] == 0 && isInside(nx,ny)){
				q.push({nx,ny});
				visit[nx][ny] = 1;
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}

int main(){
	cin >>n;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<n; j++){
			map[i][j] = s[j] - '0';
		}
	}
	
//	dfs
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 1 && !visit[i][j]){
				
				cnt = 0;
				dfs(i,j);
				v.push_back(cnt);
			}
		}
	}
	
//	bfs 
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			if(map[i][j] == 1 && visit[i][j] == 0){
//				bfs(i,j);
//			}
//		}
//	}
	cout << v.size() << '\n';
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++){
		cout << v[i] << '\n';
	}
	return 0;
}
