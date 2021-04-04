//3986 좋은 단어

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
int main(){
    cin >> n;
    stack<char> st;
    int cnt = 0;
    while(n--){
        string w;
        cin >> w;
        int len = w.size();
        for(int i=0; i<len; i++){
            if(st.empty()){
                st.push(w[i]);
            }
            else if(st.top() == w[i]){
                st.pop();
            }
            else{
                st.push(w[i]);
            }
        }
        if(st.empty()) cnt++;
        else{
            while(!st.empty()) st.pop();
        }
    }

    cout << cnt;
    return 0;
}