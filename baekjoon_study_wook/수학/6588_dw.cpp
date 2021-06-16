// 6588 골드바흐의 추측

#include <iostream>

using namespace std;
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;

    for(int i=2; i<=1000000; i++) {
        arr[i] = i;
    }
    for(int i=2; i<=1000000; i++) {
        if(arr[i] == 0) continue;
        for(int j=i+i; j<=1000000; j+=i) {
            arr[j] = 0;
        }
    }
    
    while(1) {
        cin >> n;
        if(n == 0) break;
        int i;
        bool f = false;
        for(i=2; i<n; i++) {
            if(arr[i] != 0 && arr[n-i] !=0) {
                f = true;
                break;
            }
        }
        if(f) {
            cout << n << " = " << i << " + " << n-i <<'\n';
        } else {
            cout <<"Goldbach's conjecture is wrong.";
        }
        

    }
    return 0;
}