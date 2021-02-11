// 6064 카잉달력
// 솔루션 봄
// x를 먼저 고정시키고 y를 맞추기

#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;

    while(t--){
        bool f = false;
        int m,n,x,y,k;
        cin >> m >> n >> x >> y;
        int g;
        if(m>n) g = gcd(m,n);
        else    g = gcd(n,m);
        // 최소공배수
        long long e = (long long)m*n/g; // 마지막 해
        int j=0;
        // x를 고정시키고 m만큼 증가시키며 일치하는 y 찾음
        // x는 m만큼 증가시키니 항상 일치
        // i는 i번째 해
        for(int i=x; i<=e; i+=m){
            j = i%n;
            if(j == 0) j=n;
            if(j == y){
                f = true;
                k = i;
                break;
            }
        }
        if(f) cout << k <<'\n';
        else cout << -1 <<'\n';
    }
    return 0;
}