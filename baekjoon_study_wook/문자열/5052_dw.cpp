// 5052 전화번호 목록
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int t,n;
vector<string> v;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		bool check= true;
		for(int i=0 ; i<n; i++){
			string s;
			cin >> s;
			v.push_back(s);
			m[s]=0;
		}
		sort(v.begin(), v.end());
		for(int i=0;i<n-1; i++){
			if(v[i] == v[i+1].substr(0,v[i].size())){
				check= false;
				break;
			}
		}

		if(check) cout << "YES"<< '\n';
		else	  cout << "NO" << '\n';
		v.clear();
	}
	return 0;
} 
