// 4375 1

#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    
    while(cin>>n) {
        ll a = 1;
        int cnt =1;
        while(a%n!=0) {
            a = a*10 +1 ;
            cnt++;
            a%=n;
        }
        cout << cnt <<'\n';
    }
    return 0;
}