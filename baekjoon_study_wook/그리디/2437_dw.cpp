//2437 저울

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int w[1001];
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> w[i];
    }

    sort(w, w+n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        if(sum+1 < w[i]) {
            break;
        }
        sum += w[i];
    }
    cout << sum+1;
    return 0;
}
