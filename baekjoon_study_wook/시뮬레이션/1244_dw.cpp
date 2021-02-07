//1244 스위치 켜고 끄기
#include<iostream>
using namespace std;

int n, m;
int swit[101];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> swit[i];
    }

    cin >> m;
    for(int i=0; i<m; i++){
        int s, num;
        cin >> s >> num;
        if(s == 1){ // 남학생
            for(int j=num; j<=n; j+=num){
                swit[j] = 1 - swit[j];
            }
        }
        if(s == 2){
            int left, right;
            left = right = num;
            swit[num] = 1- swit[num];
            while(1){
                left--;
                right++;
                if(left<1 || right>n) break;
                if(swit[left] != swit[right]) break;
                swit[left] = 1-swit[left];
                swit[right] = 1-swit[right];
            }
        }
    }
    // for(int i=0; i<=n/20; i++){
    //     int t = 20 * i;
    //     if(n-t >= 20){
    //         for(int j=1; j<=20; j++){
    //             cout << swit[j+t] <<' ';
    //         }
    //     }
    //     else{
    //         for(int j=1; j<=n%20; j++){
    //             cout << swit[j+t] <<' ';
    //         }
    //     }
    //     cout << '\n';
    // }
    for(int i=1; i<=n; i++){
        cout << swit[i] <<' ';
        if(i%20==0) cout << '\n';
    }
    return 0;
}