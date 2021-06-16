// 1790 수 이어 쓰기 2 -- 솔루션

#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll n, k;

ll count(int x) {
    ll sum = 0, cnt=1, digit=9, res=0;

    while(sum + digit < x) {
        sum = sum + digit;
        res = res + (cnt*digit);
        cnt++;
        digit*=10;
    }
    res += ((x-sum)*cnt);

    
    return res;
}
int main() {
    cin >> n >> k;
    ll rst = 0;
    rst = count(n);
    
    if(rst < k) {
        cout << -1;
    } else {
        ll left = 1;
        ll right = n;
        ll pos;
        while(left <= right) {
            ll mid = (left + right)/2;
            ll a = count(mid);
            
            if(a < k) {
                left = mid +1;
            } else {
                pos = mid;
                right = mid -1;
            }
            
        }
        // cout << k << ' ' << pos;
        ll c = count(pos);
        string s = to_string(pos);
        cout << s[s.size()-1 - (c-k)] << '\n';  // 끝자리에서 차이만큼 빼준다.
    }
    return 0;
}