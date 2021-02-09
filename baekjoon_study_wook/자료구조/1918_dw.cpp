// 1918 후위 표기식
/*
 솔루션봄
 i) 연산자가 ( 라면바로 스택에 넣어줍니다.

 ii) '+', '-', '*', '/' 연산자가 등장할 경우 스택에 현재 연산자보다 우선순위가 높거나 같은 기호들은 전부 결과 문자열에 추가해줍니다.

 a) '*'와 '/'가 '+'와 '-'보다 우선순위가 높습니다.
 b) 따라서, '*'와 '/'가 등장할 경우, 스택이 비거나 혹은 스택의 top이 우선순위가 낮은 기호가 나올 때까지 결과 문자열에 추가해줍니다.
 c) '+'와 '-'보다 우선순위가 낮은 기호는 없으므로 스택이 비거나 스택의 top이 괄호의 시작인 '('이 나올 때까지 결과 문자열에 추가해줍니다.

 iii) ')'가 등장할 경우 괄호의 끝이므로 스택의 top이 '('가 나올 때까지 결과 문자열에 추가해주고 마지막으로 '(' 또한 pop 해줍니다.

*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;

int main(){
    string answer="";
    cin >> s;
    stack<char> st;
    for(int i=0 ;i<s.size(); i++){
        if(s[i] >='A' && s[i] <= 'Z'){
            answer+=s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        // 우선순위가 같은 기호들 pop
        else if(s[i] == '*' || s[i] == '/' ){
            while(!st.empty() && (st.top() == '*' || st.top() == '/')){
                answer+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        // 우선순위가 같거나 높은 기호들 pop
        else if(s[i] == '+' || s[i] == '-'){
            while(!st.empty() && st.top() !='('){
                answer+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                answer+=st.top();
                st.pop();
            }
            st.pop();
        }
        

    }
    while (!st.empty())
    {
        answer+=st.top();
        st.pop();
    }
    cout << answer;
    return 0;
}