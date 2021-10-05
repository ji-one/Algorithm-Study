// 3649 로봇 프로젝트

#include <iostream>
#include <algorithm>

using namespace std;

int x, n;
int lego[1000001];

int main() {
    while(cin >> x) {
        cin >> n;
        x *= 10000000;
        for(int i=0; i< n; i++) {
            cin >> lego[i];
        }
        sort(lego, lego+n);
        int left=0,right=n-1;

        int l1, l2;
        bool danger = true;
        while(left<right) {
            int sum = lego[left] + lego[right];
            if(sum == x) {
                danger = false;
                cout << "yes " << lego[left] << ' ' << lego[right] <<'\n'; 
                break;
            } else if(sum < x) {
                left++;
            } else {
                right--;
            }
        }
        if(danger)
            cout << "danger" << '\n';
    }
    
    
    return 0;
}