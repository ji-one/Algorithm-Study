// 3425 고스택

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#define MAX 1000000000

using namespace std;

stack<int> s;
vector<string> v;

int main() {
    string str;
    int n= 0;
    while(1) {
        v.clear();
        while(1) {
            getline(cin, str);
            v.push_back(str);
            if(str == "QUIT" || str == "END") break;
            
        }
        
        if(str == "QUIT") break;

        cin >> n;
        for(int i=0; i<n; i++) {
            int value;
            cin >> value;
            s.push(value);
            int idx = 0;
            bool error = false;
            while (v[idx] != "END")
            {
                if(v[idx].substr(0,3) == "NUM") {
                    s.push(stoi(v[idx].substr(4)));
                } else if(v[idx] == "POP") {
                    if(s.empty()) {
                        error = true;
                        break;
                    }
                    s.pop();
                } else if(v[idx] == "INV") {
                    int temp = s.top();
                    s.pop();
                    s.push(-temp);
                } else if(v[idx] == "DUP") {
                    s.push(s.top());
                } else if(v[idx] == "SWP") {
                    if(s.size() < 2) {
                        error = true;
                        break;
                    }
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    s.push(a);
                    s.push(b);
                } else if(v[idx] == "ADD") {
                    if(s.size() < 2) {
                        error = true;
                        break;
                    }
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    if(abs(a+b) > MAX) {
                        error = true;
                        break;
                    }
                    s.push(a+b);
                } else if(v[idx] == "SUB") {
                    if(s.size() < 2) {
                        error = true;
                        break;
                    }
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    if(abs(b-a) > MAX) {
                        error = true;
                        break;
                    }
                    s.push(b-a);
                } else if(v[idx] == "MUL") {
                    if(s.size() < 2) {
                        error = true;
                        break;
                    }
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    if(abs((long long)b*a) > MAX) {
                        error = true;
                        break;
                    }
                    s.push(b*a);
                } else if(v[idx] == "DIV") {
                    if(s.size() < 2) {
                        error = true;
                        break;
                    }
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();

                    if(a == 0) {
                        error = true;
                        break;
                    }

                    if(a < 0 && b > 0) {
                        a= -a;
                        s.push(-(b/a));
                    } else if(a > 0 && b < 0) {
                        b= -b;
                        s.push(-(b/a));
                    } else if(a < 0 && b < 0) {
                        a= -a; b= -b;
                        s.push(b/a);
                    } else {
                        s.push(b/a);
                    }

                } else if(v[idx] == "MOD") {
                    if(s.size() < 2) {
                        error = true;
                        break;
                    }
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();

                    if(a == 0) {
                        error = true;
                        break;
                    }

                    if(a < 0 && b > 0) {
                        a= -a;
                        s.push(b%a);
                    } else if(a > 0 && b < 0) {
                        b= -b;
                        s.push(-(b%a));
                    } else if(a < 0 && b < 0) {
                        a= -a; b= -b;
                        s.push(-(b%a));
                    } else {
                        s.push(b%a);
                    }

                }
                idx++;
            }

            if(s.size() != 1) {
                error = true;
            }

            if(error) {
                cout << "ERROR" << '\n';
            } else {
                cout << s.top() << '\n';
            }
            while(!s.empty()) {

                s.pop();
            }

        }
        cout << '\n';
    }
    return 0;
}