// 2012 등수 매기기

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int r[500001];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> r[i];
    }
    sort(r, r+n+1);

    long long answer = 0;
    for(int i=1; i<=n; i++) {
        answer += abs(i - r[i]);
    }
    cout << answer;
    return 0;
}