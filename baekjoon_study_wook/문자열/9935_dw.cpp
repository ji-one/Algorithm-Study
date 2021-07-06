// 9935 문자열 폭발
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string s;
string b;
int main(){
    stack<char> st;
    stack<char> tmp;
    cin >> s >> b;

    int asd = 0;
    for(int i=0; i<s.size(); i++){
        st.push(s[i]);

        if(!st.empty() && b.back() == st.top()){
            bool bomb = true;
            int cnt = 0;
            for(int j=b.size()-1; j>=0; j--){
                if(st.empty()){
                    bomb = false;
                    break;
                }
                if(b[j] != st.top()){
                    bomb = false;
                    break;
                }
                tmp.push(st.top());
                st.pop();
                cnt++;
            }
            if(bomb){
                // while(!tmp.empty()){
                //     tmp.pop();
                // }
                asd++;
            }
            else{   // 복구
                while(cnt--){
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
        }
    }

    string ans="";
	if(st.size() == 0) ans = "FRULA";
	else{
		while(!st.empty()){
			ans += st.top();
			st.pop();
		}
		reverse(ans.begin(), ans.end());
	}
	cout << asd;

    
    return 0;
}