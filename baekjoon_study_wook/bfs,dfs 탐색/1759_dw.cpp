// 1759 암호 만들기 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
char arr[16];
int visit[16];

void dfs(int cnt, int x, string s){
	if(cnt == l){
		int mo = 0;
		int ja = 0;
		for(int i=0; i<l; i++){
			if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'){
				mo++;
			}
			else{
				ja++;
			}
		}
		if(mo>0 && ja>1) cout << s << '\n';
		return ;
	}
	
	for(int i=x; i<c;i ++){
		if(visit[i]) continue;
		visit[i] = 1;
		dfs(cnt+1, i, s+arr[i]);
		visit[i] = 0;
	}
	
}
int main(){
	cin >> l >> c;
	for(int i=0; i<c; i++){
		cin >> arr[i];
	}
	sort(arr, arr+c);
	dfs(0,0,"");
	return 0;
} 
