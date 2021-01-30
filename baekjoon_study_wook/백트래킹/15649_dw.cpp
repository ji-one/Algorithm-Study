//15649 N°úM (1)
#include <iostream>
#include <vector>
using namespace std;

int n,m;
int sel[9];
vector<int> v;

void dfs(int cnt){
	if(cnt == m){
		for(int i=0; i<m; i++){
			cout << v[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for(int i=1; i<=n; i++){
		if(sel[i] == 1) continue;
		v.push_back(i);
		sel[i] = 1;
		dfs(cnt+1);
		v.pop_back();
		sel[i] = 0;
	}
}
int main(){
	cin >> n >> m;
	
	dfs(0);
	return 0;
} 
