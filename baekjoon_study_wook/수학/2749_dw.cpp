// 2749 피보나치 수 3

#include <iostream>

using namespace std; 

typedef long long ll;

ll n;
struct matrix {
    ll data[2][2];
};

matrix multiply(matrix a, matrix b) {
    matrix c;
    c.data[0][0] = (a.data[0][0]*b.data[0][0] + a.data[0][1]*b.data[1][0])%1000000;
    c.data[0][1] = (a.data[0][0]*b.data[0][1] + a.data[0][1]*b.data[1][1])%1000000;
    c.data[1][0] = (a.data[1][0]*b.data[0][0] + a.data[1][1]*b.data[1][0])%1000000;
    c.data[1][1] = (a.data[1][0]*b.data[0][1] + a.data[1][1]*b.data[1][1])%1000000;

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
        m = multiply(m,t);
    }

    return m;
}
int main() {  
    cin >> n;

    matrix a;
    a.data[0][0] = 1, a.data[0][1] = 1;
    a.data[1][0] = 1, a.data[1][1] = 0;

    a = divide(a, n);

    cout << a.data[0][1];
    return 0;
}