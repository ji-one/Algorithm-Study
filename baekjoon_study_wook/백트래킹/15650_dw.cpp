//15650 N°úM (2)
#include <iostream>
#include <vector>
using namespace std;

int n,m;
int sel[9];
vector<int> v;

void dfs(int cnt,int x){
	if(cnt == m){
		for(int i=0; i<m; i++){
			cout << v[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for(int i=x; i<=n; i++){
		if(sel[i] == 1) continue;
		v.push_back(i);
		sel[i] = 1;
		dfs(cnt+1,i);
		v.pop_back();
		sel[i] = 0;
	}
}
int main(){
	cin >> n >> m;
	
	dfs(0,1);
	return 0;
} 
