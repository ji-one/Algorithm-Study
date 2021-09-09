// 1783 병든 나이트

#include <iostream>
#include <algorithm>

using namespace std;

int n , m;

int main() {
    cin >> n >> m;
    int answer = 0;
    if(n==1) {  // 세로 한칸
        cout << 1;
    } else if(n==2) {   // 세로 두칸

        cout << min((m+1)/2, 4);
    } else {
        if(m<=6) {
            cout << min(4, m);
        } else {
            cout << m-2;
        }
    }
    return 0;
}