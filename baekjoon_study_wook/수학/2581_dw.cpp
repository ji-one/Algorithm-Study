// 2581 소수
#include <iostream>

using namespace std;

int num[10001];
int main() {
    int m, n;
    cin >> m >> n;
    for(int i=2; i<=n; i++) {
        num[i] = i;
    }

    for(int i=2; i<=n; i++) {
        for(int j=i+i; j<=n; j+=i) {
            num[j] = 0;
        }
    }

    int sum=0;
    int minValue=n;
    for(int i=m; i<=n; i++) {
        if(num[i] != 0) {
            sum+=i;
            if(minValue > i) {
                minValue = i;
            }
        }
    }
    if(sum == 0) {
        cout << -1;
    } else {
        cout << sum << ' ' << minValue;
    }
    return 0;
}