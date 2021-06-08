// 14438 수열과 쿼리 17 솔루션

/*
    일반적으로 for문을 이용해 값을 구하면 O(n*m) 이므로 시간이 오래 걸린다 
    따라서 세그먼트 트리를 이용하여 더 빠른 시간에 구할 수 있다. O(m * logN)
    트리 노드에 구간에서의 최소값을 넣어 준다.
*/
#include <iostream>
#include <algorithm>
#define MAX 1987654321;

using namespace std;

int n, m;
int a[100001];
int tree[100001 * 4];

int init(int start, int end, int node) {
    // 자식 노드 중 더 작은 값을 현재 노드로 하는 세그먼트 트리 생성
    if(start == end) return tree[node] = a[start];
    int mid = (start + end)/2;
    return tree[node] = min(init(start, mid, node*2) , init(mid+1, end, node*2+1));
}

int update(int start, int end, int node, int index) {
    // 값이 벗어나면 현재 노드 리턴
    if(index < start || index > end) return tree[node];
    // 리프 노드에 도달하면 값 수정 후 리턴
    if(start == end) return tree[node] = a[index];
    int mid = (start + end)/2;
    // 수정된 값으로 최소값 트리 재구성
    return tree[node] = min(update(start, mid, node*2, index), update(mid+1, end, node*2+1, index));
}

int findMinValue(int start, int end, int node, int left, int right){
    // 범위 밖
    if(start > right || end < left) 
        return MAX;
    // 범위 내
    if(start >= left && end <= right) 
        return tree[node];

    int mid = (start + end) /2;
    return min(findMinValue(start, mid, node*2, left, right), findMinValue(mid+1, end, node*2+1, left, right));
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    // 세그먼트 트리 생성
    init(1, n, 1);
    
    cin >> m;
    for(int idx=0; idx<m; idx++) {
        int q, i, j;
        cin >> q >> i >> j;
        if(q == 1) {
            a[i] = j;
            update(1, n, 1, i);
        } else {
            // i~j 최소값 구하기
            cout << findMinValue(1, n, 1, i, j)<<'\n';
        }
    }
}