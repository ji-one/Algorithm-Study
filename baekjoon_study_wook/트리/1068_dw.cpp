// 11725 트리의 부모 찾기
#include <iostream>
#include <vector>

using namespace std;

int n, rst;
vector<int> v[51];
int node[51];
int visit[51];
void dfs(int node){
	visit[node]=1;
	if(v[node].size() == 0){
		rst++;
	}
	else{
		for(int i=0 ; i<v[node].size(); i++){
			int nn = v[node][i];
			if(!visit[nn]){
				dfs(nn);
			}
		}
	}
	
}
int main(){
	cin >> n;
	int root;
	for(int i=0; i<n; i++){
		int tmp;
		cin >>tmp;
		if(tmp == -1){
			root = i;
		}
		v[tmp].push_back(i);
		
	}
	
	int x;
	cin >> x;
	if(x==root){
		cout << 0;
		return 0;
	}
	for(int i=0 ;i<n; i++){
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == x && v[i].size()>=2){
				rst--;
			}
		}
	}
	v[x].clear();
	
	dfs(root);
	cout << rst;
	return 0;
}
