// 2470 두 용액

#include <iostream>
#include <algorithm>
#define MAX 2100000000

using namespace std;

int liquid[100001];
int n;

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> liquid[i];
    }

    sort(liquid, liquid + n);

    int i=0, j=n-1;
    int minValue = MAX;
    int left=0, right=0;
    while(i<j) {
        int sum = liquid[i] + liquid[j];
        if(abs(sum) < minValue) {
            minValue = abs(sum);
            left = i;
            right = j;
        }

        if(sum < 0) {
            i++;
        } else {
            j--;
        }
    }

    cout << liquid[left] << ' ' << liquid[right];
    return 0;
}
