#include <iostream>
#include <string>
#include <set>
using namespace std;

int m;
set<int> s;
set<int> allset = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int main(){
	
	ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> m;
	while(m--){
		string str;
		int n;
		cin >> str;
		if(str == "add"){
			cin >> n;
			if(s.find(n) != s.end()) continue;
			s.insert(n);
		}
		else if(str == "check"){
			cin >> n;
			if(s.find(n) != s.end()) cout << 1 << '\n';
			else	cout << 0 <<'\n';
		}
		else if(str == "remove"){
			cin >> n;
			if(s.find(n) != s.end()) s.erase(n);
		}
		else if(str == "toggle"){
			cin >> n;
			if(s.find(n) != s.end()) s.erase(n);
			else	s.insert(n);
		}
		else if(str == "all"){
			s = allset;
		}
		else if(str == "empty"){
			s.clear();
		}
	}
	return 0;
}