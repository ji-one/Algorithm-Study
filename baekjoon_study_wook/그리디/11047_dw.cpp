// 11047 동전 0

#include <iostream>

using namespace std;

int n,k;
int coin[11];
int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }
    int rst = 0;
    while(n-- || k != 0){
        if(coin[n] <= k){
            rst +=(k/coin[n]);
            k %= coin[n];
        }
    }
    cout << rst ;
    return 0;
}