//9935 ¹®ÀÚ¿­ Æø¹ß
#include <iostream>
#include <stack>
using namespace std; 

string str, b;
stack<char> st;
int main(){
	cin >> str >> b;
	int n = b.size();
	for(int i=0; i<str.size(); i++){
		st.push(str[i]);
		if(st.size()>=b.size() && b[n-1] == str[i]){
			int k=0;
			for(int j=b.size()-1; j>=0; j--){
				if(b[j] == st.top()){
					k++;
					st.pop();
				}
				else
					break;
					
			}
			if(k != b.size()){
				for(int j=0; j<k; j++){
					st.push(b[j]);
				}
				
			}
		}
	}
	
	string ans="";
	if(st.size() == 0) ans = "FRULA";
	else{
		while(!st.empty()){
			ans = st.top() + ans;
			st.pop();
		}
		
	}
	cout << ans;
	return 0;	
}
