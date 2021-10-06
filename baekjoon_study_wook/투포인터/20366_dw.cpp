// 20366 같이 눈사람 만들래?

#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 2100000000

using namespace std;

int n;
int snow[601];
int main() {
    cin>> n;
    for(int i=0; i<n; i++) {
        cin >> snow[i];
    }
    sort(snow, snow+n);
    int ans = MAX;

    for(int i=0; i<n-3; i++) {
        for(int j=i+3; j<n; j++) {
            int left = i+1;
            int right = j-1;
            int ellsa = snow[i] + snow[j];
            while(left < right) {
                int anna = snow[left] + snow[right];
                int diff = ellsa - anna;
                ans = min(ans, abs(diff));
                if(diff > 0) {
                    left++;
                } else if(diff < 0){
                    right--;
                } else {
                    break;
                }
            }
        }
    }

    cout << ans;
    return 0;
}