//4949 ±ÕÇüÀâÈù ¼¼»ó 

#include <iostream>
#include <stack>

using namespace std;

string str;
stack<char> s;
int main(){
	while(1){
		getline(cin, str);
		
		if(str[0] == '.') {
			break;
		}
		bool chk = true;
		
		for(int i=0; i<str.size(); i++){
			if(str[i] == '(' || str[i] == '[')
				s.push(str[i]);
				    
			else if(str[i] == ')'){
				if(s.empty()){
					chk = false;
					break;
				}
				else if(s.top() == '['){
					chk = false;
					break;
				}
				s.pop();
			}
			else if(str[i] == ']'){
				if(s.empty()){
					chk = false;
					break;
				}
				else if(s.top() == '('){
					chk = false;
					break;
				}
				s.pop();
			}
			
		}
		if(!chk || !s.empty()) cout << "no" << '\n';
		else	cout << "yes"  << '\n';
		while(!s.empty()) s.pop();
	}
	return 0;
} 
