// 2504 괄호의 값   솔루션 봄
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> st;


int main(){
    cin >> str;
    bool flag=true;
    int sum = 0;
    int tmp = 1;
    for(int i=0; i<str.size(); i++){
        
        if(str[i] == '('){
            tmp*=2;
            st.push(str[i]);
        }
        if(str[i] == ')'){
            if(st.size() == 0){
                flag = false;
                break;
            }
            if(st.top() != '('){
                flag = false;
                break;
            }
            if(str[i-1] == '('){
                sum += tmp;
            }
            st.pop();
            tmp/=2;

        }
        if(str[i] == '['){
            tmp*=3;
            st.push(str[i]);
        }
        if(str[i] == ']'){
            if(st.size() == 0){
                flag = false;
                break;
            }
            if(st.top() != '['){
                flag = false;
                break;
            }
            if(str[i-1] == '['){
                sum += tmp;
            }
            st.pop();
            tmp/=3;

        }
    }

    if(flag && st.empty()) cout << sum;
    else     cout << 0;
    return 0;
}