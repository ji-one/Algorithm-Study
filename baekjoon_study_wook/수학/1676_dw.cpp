// 1676 팩토리얼 0의 개수
#include <iostream>

using namespace std;

int n;
int main(){
    cin >> n;
    int rst=0;
    for(int i=1; i<=n; i++){
        if(i%5 == 0) // 10을 만들 수 있다.
            rst++;
        if(i%25 == 0)   // 100을 만들 수 있다.
            rst++;
        if(i%125 == 0) // 1000을 만들 수 있다.
            rst++;
    }
    cout << rst;
    return 0;
}