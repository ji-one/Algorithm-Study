//9935 문자열 폭발
#include <iostream>
#include <vector>
using namespace std; 

string str, b;
vector<char> st;
int main(){
	cin >> str >> b;
	int n = b.size();
	
	for(int i=0; i<str.size(); i++){
		st.push_back(str[i]);
		if(b[n-1] == str[i]){
			int k = st.size()-1;
			bool check=true;
			for(int j=n-1; j>=0; j--){
				if(b[j] != st[k--]){
					check = false;
					break;
				}
			}
			if(check){
				for(int j=0; j<n; j++){
					st.pop_back();
				}
			}
		}
	}
	
	string ans="";
	if(st.size() == 0) ans = "FRULA";
	else{
		for(int i=0; i<st.size(); i++){
			ans += st[i];
		}
	}
	cout << ans;
	return 0;	
}
