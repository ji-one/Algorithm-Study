// 1935 후위 표시식 2

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n;
string s;
int alpha[27];

double cal(double a, double b, char op) {
    if(op == '+') {
        return a + b;
    } else if(op == '-') {
        return a - b;
    } else if(op == '*') {
        return a * b;
    } else {
        return a/b;
    }
}
int main() {
    cin >> n;
    cin >> s;
    for(int i=0; i<n; i++) {
        cin >> alpha[i];
    }

    double rst = 0;
    stack<double> st;
    for(int i=0; i<s.size(); i++) {
        if(s[i] >= 'A' && s[i] <='Z') {
            st.push(alpha[s[i]-'A']);
        } else {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            double c = cal(b, a, s[i]);
            st.push(c);
        }
    }

    printf("%.2f", st.top());
    return 0;
}