//14889 스타트와 링크
#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[21][21];
int visit[21];
int rst = 5000000;
vector<int> a;
vector<int> b;
void dfs(int cnt, int x){
//	팀을 다 나눈 경우 
	if(cnt == n/2){
		
		for(int i=1; i<=n; i++){
			if(visit[i])
				a.push_back(i);
			else
				b.push_back(i);
		}
		
//		for(int i=0; i<a.size(); i++){
//			cout << a[i] <<' ';
//		}
//		cout << '\n';
		
		int start=0;
		int link = 0;
		for(int i=0; i<n/2; i++){
			for(int j = i+1; j<n/2;j++){
				int tmp1 = a[i];
				int tmp2 = a[j];
				start += (arr[tmp1][tmp2] + arr[tmp2][tmp1]);
				
				int tmp3 = b[i];
				int tmp4 = b[j];
				link += (arr[tmp3][tmp4] + arr[tmp4][tmp3]);
			}
		}
		a.clear();
		b.clear();
		
		rst = min(rst, abs(start-link) );
		return ;
	}
	for(int i=x; i<=n; i++){
		if(visit[i]) continue;
		visit[i] = 1;
		dfs(cnt+1, i);
		visit[i] = 0;
	}
}

int main(){
	cin >>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> arr[i][j];
	
	dfs(0,1);
	
	cout << rst;
	return 0;
} 
