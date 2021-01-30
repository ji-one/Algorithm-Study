//6603 ·Î¶Ç
#include <iostream>
#include <vector>
using namespace std;

int n,arr[13];
int visit[50];
vector<int> v;

void dfs(int cnt, int x){
	if(cnt == 6){
		for(int i=0; i<6; i++){
			cout << v[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for(int i=x; i<n;i++){
		int num = arr[i];
		if(visit[num]) continue;
		visit[num] = 1;
		v.push_back(num);
		dfs(cnt+1, i);
		v.pop_back();
		visit[num] = 0;
	}
}
int main(){
	
	while(1)
	{
		cin >> n;
		if(n == 0) break;

		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		
		dfs(0,0);
		cout << '\n';
		
		fill(arr,arr+n,0);
	}
	return 0;
} 
