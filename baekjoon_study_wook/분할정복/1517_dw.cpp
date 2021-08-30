// 1517 버블 소트

#include <iostream>

using namespace std;

int n;
int a[500001];
int b[500001];
long long cnt = 0;
void conquer(int left, int mid, int right) {
    int i,j,k,l;
    i = left;
    j = mid+1;
    k = left;
    
    while(i <= mid && j <= right) {
        if(a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            cnt +=( mid - i + 1);
            b[k++] = a[j++];

        }
    }

    if(i>mid) {
        for(l=j; l<=right; l++) {
            b[k++] = a[l];
        }
    } else {
        for(l=i; l<=mid; l++) {
            b[k++] = a[l];
        }
    }

    for(l = left; l<=right; l++) {
        a[l] = b[l];
    }
    return ;
}

void divide(int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        divide(start, mid);
        divide(mid+1, end);
        conquer(start, mid, end);
    }

}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    divide(0, n-1);
    cout << cnt;
    return 0;
}