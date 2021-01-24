//15651 N°úM (3)
#include <iostream>
#include <vector>
using namespace std;

int n,m;
int sel[8];
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
		v.push_back(i);
		dfs(cnt+1);
		v.pop_back();
	}
}
int main(){
	cin >> n >> m;
	
	dfs(0);
	return 0;
} 
