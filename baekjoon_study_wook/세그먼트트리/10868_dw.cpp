// 10868 최솟값

#include <iostream>
#include <algorithm>
#define MAX 1987654321

using namespace std;

int n, m;
int arr[100001];
int tree[100001*4];

int init(int start, int end, int node) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

int query(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return MAX;
    if(left <= start && right >= end)
        return tree[node];
    int mid = (start + end)/2;
    return min(query(start, mid, node*2, left, right), query(mid+1, end, node*2+1, left, right));
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    // 세그먼트 트리 생성
    init(1, n, 1);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, n, 1, a, b) << '\n';
    }
    return 0;
}