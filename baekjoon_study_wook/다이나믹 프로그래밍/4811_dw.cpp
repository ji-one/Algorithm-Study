// 4811 알약 -- 솔루션

#include <iostream>

using namespace std;

long long drug[31];

// long long drug[31][31];

/*
long long init(int w, int h) {

    if(w<0 || h <0) return 0;
    // 한개짜리 알약이 없으면 반개하나를 먹는 경우 밖에 없음
    if(w == 0) return 1;

    if(drug[w][h] != 0) return drug[w][h];

    // 약 하나를 반갈라 먹거나 약 반개를 먹거나
    return drug[w][h] = init(w, h-1) + init(w-1, h+1);

}
*/

int main() {
    int n;
    drug[0] = 1;
    drug[1] = 1;
    drug[2] = 2;

    // W()H() -- ()<- 안에 WH 한쌍을 넣을 수 있는 경우
    for(int i=3; i<=30; i++) {
        for(int j=0; j<i; j++) {
            drug[i] += (drug[j] * drug[i-j-1]);
        }
    }

    // init(30,0);
    
    while (1)
    {
        cin >> n;
        if(n == 0) break;

        cout << drug[n] << '\n';
    }
    
    return 0;
}

/*
WH

WWHH
WHWH

WWWHHH
WWHWHH
WWHHWH
WHWWHH
WHWHWH

*/