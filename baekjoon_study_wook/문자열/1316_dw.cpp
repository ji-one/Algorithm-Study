// 그룹 단어 체커1316 
#include <iostream>

using namespace std;

int n, cnt;
int a[26];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		int c = 1;
		fill(a,a+26,0);
		for(int j=0; j<str.size(); j++){
			if(a[str[j] - 'a'] == 0 && str[j] != str[j+1]){
				a[str[j] - 'a'] = 1;
				
			}
			else if(a[str[j] - 'a'] == 1){
				c = 0;
				break;
			}
			
		}
		if(c == 1) {
			cnt++;
		}
	}
	
	cout << cnt << '\n';
	return 0;
}
