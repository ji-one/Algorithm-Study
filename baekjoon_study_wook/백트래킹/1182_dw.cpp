// 1182 부분수열의 합
#include <iostream>
#include <vector>
using namespace std;

int n,s;
int arr[21];
int visit[21];
int rst;
vector<int> v;

void dfs(int cnt, int x){
	if(cnt!=0){
		int sum=0;
		for(int i=0; i<cnt; i++){
			sum+=v[i];
		}
		if(sum == s) {
			rst ++;
//			cout << sum << '\n';
//			for(int i=0; i<v.size(); i++){
//				cout << v[i] <<' ';
//			}
//			cout << '\n';
		}
	}
	
	for(int i=x; i<n;i++){
		if(visit[i] == 1) continue;
		visit[i] = 1;
		v.push_back(arr[i]);
		dfs(cnt+1, i);
		v.pop_back();
		visit[i] = 0;
	}
}
int main(){
	cin >> n >> s; 
	for(int i = 0 ;i<n; i++){
		cin >> arr[i];
	}
	
	dfs(0,0);
	
	cout << rst <<'\n';
	return 0;
} 
