// 1629 곱셈
/*
    솔루션 봄
    a^b = a^(b/2) * a^(b/2) => O(2*log N) 시간이 걸린다.
    분할 정복
*/ 

#include <iostream>
using namespace std;

long long divCon(int a, int b, int c){
    if(b==0) return 1;

    if(b%2==0){ // 짝수면
        long long tmp = divCon(a, b/2, c);
        return (tmp*tmp)%c;
    }
    else{   // 홀수면 짝수로 만들어 준다
        return (a*divCon(a,b-1,c))%c;
    }
}

int main(){

    int a,b,c;
    long long ans;

    cin >> a >> b >> c;
    ans = divCon(a,b,c);
    cout << ans << '\n';
    return 0;
}