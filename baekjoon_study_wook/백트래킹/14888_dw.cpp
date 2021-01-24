// 14888 연산자 끼워넣기 
#include <iostream>
#include <vector>
using namespace std;

int n;
int num[12];
int arr[11];
int op[4]; // + - x /

int maxV = -1000000000;
int minV = 1000000000;

vector<int> v;
void dfs(int cnt){
	if(cnt == n-1){
		int rst=num[0];
		
		for(int i=1; i<n; i++){
			int tmp = v[i-1];
			if(tmp == 0){
				rst+=num[i];
			}
			else if(tmp == 1){
				rst-=num[i];
			}
			else if(tmp == 2){
				rst*=num[i];
			}
			else if(tmp == 3){
				rst/=num[i];
			}
		}
		
		maxV = max(maxV, rst);
		minV = min(minV, rst);
		return ;
	}
	
	for(int i=0; i<4; i++){
		if(op[i] ==0) continue;
		op[i]--;
		v.push_back(i);
		dfs(cnt+1);
		v.pop_back();
		op[i]++;
		
		
	}
	
}
int main(){
	cin >> n;
	for(int i=0; i<n;i++){
		cin >> num[i];
	}
	for(int i=0; i<4;i++){
		cin >> op[i];
	}
	
	dfs(0);
	
	cout << maxV << '\n' << minV ;
	return 0;
}
