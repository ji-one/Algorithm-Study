// 9093 단어 뒤집기
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string str;
stack<char> st;
int main(){
    cin >> n;
    cin.ignore();   // 버퍼 비우기
    for(int i=0; i<n; i++){
        getline(cin, str);
        string rst = "";
        for(int j=0; j<str.size(); j++){
            if(str[j] == ' '){
                while(!st.empty()){
                    rst += st.top();
                    st.pop();
                }
                rst += ' ';
            }
            else{
                st.push(str[j]);
            }
        }
        while(!st.empty()){
            rst += st.top();
            st.pop();
        }

        cout << rst << '\n';
        
    }
    
    return 0;
}