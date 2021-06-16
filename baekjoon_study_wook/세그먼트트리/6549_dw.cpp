// 히스토그램에서 가장 큰 직사각형 --솔루션
/*
    세그먼트 트리에 최소높이의 인덱스를 저장
    최소 높이의 인덱스 왼쪽, 오른쪽 구간을 분할 하여 
    다시 최소 인덱스를 찾은 후 넓이가 최대인 곳을 찾는다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int tree[100001*4];

int init(int start, int end, int node) {
    if(start == end) return tree[node] = start;
    int mid = (start + end)/2;

    int leftMinIndex = init(start, mid, node*2);
    int rightMinIndex = init(mid+1, end, node*2+1);
    
    if(arr[leftMinIndex] <= arr[rightMinIndex]) {
        return tree[node] = leftMinIndex;
    } else {
        return tree[node] = rightMinIndex;
    }
}

int query(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return -1;
    if(left <= start && right >= end) return tree[node];

    int mid = (start + end)/2;

    int li = query(start, mid, node*2, left, right);
    int ri = query(mid+1, end, node*2+1, left, right);

    if(li == -1) {
        return ri;
    } else if(ri == -1) {
        return li;
    } else {
        return arr[li] <= arr[ri] ? li : ri;
    }
}

long long getMaxArea(int start, int end) {

    int minIndex = query(1, n, 1, start, end);


    long long area = (long long)(end-start+1) * arr[minIndex];

    if(minIndex > start) {
        long long tmp = getMaxArea(start, minIndex-1);

        area = max(tmp, area);
    }

    if(minIndex < end) {
        long long tmp = getMaxArea(minIndex+1, end);

        area = max(tmp, area);
    }

    return area;
}
int main(){
    while(1) {
        cin >> n;
        if(n == 0) {
            break;
        }
        for(int i=1; i<=n; i++) {
            cin >> arr[i];
        }

        init(1,n,1);

        // 구간 넓이
        cout << getMaxArea(1, n) << '\n';
    }
    return 0;
}