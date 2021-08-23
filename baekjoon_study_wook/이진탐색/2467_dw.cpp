// 2467 용액

#include <iostream>
#define MAX 2100000000

using namespace std;

int n, a, b;
int liquid[100001];
int sum = MAX;

void binarySearch(int current, int end) {
    int low = current+1;
    int high = end;
    while(low<=high) {
        int mid = (low + high)/2;
        int tmp = liquid[current] + liquid[mid];
        if(abs(tmp) <= sum) {
            sum = abs(tmp);
            a = liquid[current];
            b = liquid[mid];
        }
        
        if(tmp > 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> liquid[i];
    }
    
    // 이분탐색
    for(int i=0; i<n; i++) {
        binarySearch(i, n-1);
    }


    //  투포인터
    // int left = 0;
    // int right = n-1;
    // int a, b, sum = MAX;
    // while(left < right) {
    //     int tmp = liquid[left] + liquid[right];
    //     if( abs(tmp) <= sum ) {
    //         sum = abs(tmp);
    //         a = liquid[left];
    //         b = liquid[right];
    //     }

    //     if(tmp > 0) {
    //         right--;
    //     } else {
    //         left++;
    //     }
    // }

    
    cout << a << ' ' << b;


    return 0;
}