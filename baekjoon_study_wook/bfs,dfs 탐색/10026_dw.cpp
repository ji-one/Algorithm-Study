// 10026 적록색약 
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n;
string str[101];
int visit[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

vector<int> v;

bool isInside(int x, int y){
	return (x>=0 && x<n && y>=0 && y<n);
}

void bfs(int x, int y){
	char c = str[x][y];
	queue<pair<int,int>> q;
	visit[x][y] = 1;
	q.push({x,y});
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(isInside(nx, ny) && str[nx][ny] == c && !visit[nx][ny]){
				q.push({nx,ny});
				visit[nx][ny] = 1;
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> str[i];
	}
	
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visit[i][j]){
				bfs(i,j);
				cnt++;
			}
		}
	}
	v.push_back(cnt);
	
	
	memset(visit, 0, sizeof(visit));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(str[i][j] == 'G'){
				str[i][j] = 'R';
			}
		}
	}
	
	cnt =0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visit[i][j]){
				bfs(i,j);
				cnt++;
			}
		}
	}
	v.push_back(cnt);
	
	cout << v[0] << ' ' << v[1];
	return 0;
}
