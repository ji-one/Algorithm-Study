// 11444 피보나치 수 6
// 피보나치 행렬 분할을 이용
// O(log N) 으로 구할 수 있다

#include <iostream>

using namespace std;
typedef long long ll;

struct matrix {
    ll data[2][2];
};

ll n;

matrix multiply(matrix a, matrix b) {
    matrix c;
    c.data[0][0] = (a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0])%1000000007;
    c.data[0][1] = (a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1])%1000000007;
    c.data[1][0] = (a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0])%1000000007;
    c.data[1][1] = (a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1])%1000000007;

    return c;
}
matrix divide(matrix m, ll x) {
    if(x == 1) {
        return m;
    }

    m = divide(m, x/2);
    m = multiply(m, m);
    if(x%2) {
        matrix t;
        t.data[0][0] = 1, t.data[0][1] = 1;
        t.data[1][0] = 1, t.data[1][1] = 0;
        m = multiply(m, t);
    }
    return m;
}
ll fibo(ll x) {
    matrix a;
    // F(1) 설정
    a.data[0][0] = 1, a.data[0][1] = 1;
    a.data[1][0] = 1, a.data[1][1] = 0;
    // 분할
    a = divide(a, x);
    return a.data[0][1];
}
int main(){
    cin >> n;

    if(n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    cout << fibo(n) <<'\n';
    

    return 0;
}