#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(st.empty())
            st.push(s[i]);
        else{
            if(st.top() != s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
    }
    return st.size()==0? 1 : 0;
    // return answer;
}