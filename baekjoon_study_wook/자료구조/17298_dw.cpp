// 17298 오큰수 

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;
    stack<pair<int, int>> st;
    vector<int> v(n);

    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(st.empty()) {
            st.push({a, i});
        } else {
            if(st.top().first < a) {
                while(!st.empty()) {
                    if(st.top().first >= a) {
                        break;
                    }
                    v[st.top().second] = a;
                    st.pop();
                }
            }
            st.push({a,i});
        }
    }

    while(!st.empty()) {
        
        v[st.top().second] = -1;
        st.pop();
    }
    for(int i=0; i<n; i++) {
        cout << v[i] << ' ';
    }
    return 0;
}