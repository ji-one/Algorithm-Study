// 5397 키로거

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int testCase;
string keylog;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> testCase;
    while(testCase--){
        string pw = "";
        stack<char> st;
        stack<char> tmp;

        cin >> keylog;
        int len = keylog.size();
        for(int i=0;i<len; i++){
            if(keylog[i] == '<'){
                if(st.empty()) continue;
                tmp.push(st.top());
                st.pop();
            }
            else if(keylog[i] == '>') {
                if(tmp.empty()) continue;
                st.push(tmp.top());
                tmp.pop();
            }
            else if(keylog[i] == '-') {
                if(st.empty()) continue;
                st.pop();
            }
            else {
                st.push(keylog[i]);
            }
        }
        while(!st.empty()){
            tmp.push(st.top());
            st.pop();
        }

        while(!tmp.empty()){
            cout << tmp.top();
            tmp.pop();
        }
        
        cout << '\n';

    }
    return 0;
}