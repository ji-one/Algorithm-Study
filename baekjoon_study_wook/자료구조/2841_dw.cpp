// 2841 외계인의 기타 연주

#include <iostream>
#include <stack>

using namespace std;

int n, p;
int main() {
    cin >> n >> p;
    stack<int> st[7];

    int ans = 0;
    for(int i=0; i<n; i++) {
        int line, num;
        cin >> line >> num;

        if(st[line].empty()) {
            st[line].push(num);
            ans++;
        } else {
            if(st[line].top() < num) {
                st[line].push(num);
                ans++;
            } else if(st[line].top() > num) {
                while(!st[line].empty() && st[line].top() > num) {
                    st[line].pop();
                    ans++;
                }
                
                if(!st[line].empty() && st[line].top() == num) 
                    continue;
                 
                st[line].push(num);
                ans++;
                
            }
        }

    }

    cout << ans;

    return 0;
}