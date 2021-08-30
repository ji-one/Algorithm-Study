// 18436 수열과 쿼리 36

#include <iostream>

using namespace std;

int n,m;
int arr[100001];
int tree[100001*4];

int init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = arr[start]%2;
    }
    int mid = (start + end)/2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

void update(int start, int end, int curIndex, int changeIndex, int x) {
    if(changeIndex < start || changeIndex > end) return ;
    tree[curIndex] += x;
    if(start == end) return ;
    int mid = (start + end)/2;
    update(start, mid, curIndex*2, changeIndex, x);
    update(mid+1, end, curIndex*2+1, changeIndex, x);
}

int count(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return tree[node];
    int mid = (start+end)/2;
    return count(start, mid, node*2, left, right) + count(mid+1, end, node*2+1, left, right);
}

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    init(1,n,1);
    cin >> m;
    for(int i=0; i<m; i++) {
        int query;
        cin >> query;
        if(query == 1) {
            int idx, x;
            cin >> idx >> x;
            if(arr[idx]%2 != x%2) {
                if(x%2 == 1)
                    update(1, n, 1, idx, 1);
                else
                    update(1, n, 1, idx, -1);
            }
            arr[idx] = x;
        } else {
            int l, r;
            cin >> l >> r;
            int oddCnt = count(1, n, 1, l, r);
            if( query == 2) {
                cout << (r-l+1) - oddCnt << '\n';
            } else {
                cout << oddCnt << '\n';
            }
        }
    }

    return 0;
}