// 1449 수리공 항승

#include <iostream>
#include <algorithm>

using namespace std;

int n, l;
int pipe[1001];

int main() {
    cin >> n >> l;
    for(int i=0; i<n; i++) {
        cin >> pipe[i];
    }
    sort(pipe, pipe+n);

    int cnt = 1;
    double tape = pipe[0] - 0.5 + l;
    for(int i=1; i<n; i++) {
        if(pipe[i] + 0.5 > tape) {
            cnt++;
            tape = pipe[i] - 0.5 + l;
        }
    }
    cout << cnt;
    return 0;
}