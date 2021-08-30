// 11505 구간 곱 구하기

#include <iostream>
#define MOD 1000000007

using namespace std;

int n, m, k;
int arr[1000001];
long long tree[1000001*4];

long long init(int start, int end, int node) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = (init(start, mid, node*2) * init(mid+1, end, node*2+1))%MOD;
}

long long update(int start, int end, int curIndex, int changeIndex, int after) {

    if(changeIndex < start || changeIndex > end) return tree[curIndex];
    if(start==end) return tree[curIndex] = after;
    int mid = (start+end)/2;
    
    return tree[curIndex] = (update(start, mid, curIndex*2, changeIndex, after) * update(mid+1, end, curIndex*2+1, changeIndex, after))%MOD;
}

long long multi(int start, int end, int curIndex, int left, int right) {
    if(left > end || right < start) return 1;
    if(left <= start && right >= end) return tree[curIndex];
    int mid = (start + end)/2;
    return (multi(start, mid, curIndex*2, left, right) * multi(mid+1, end, curIndex*2+1, left, right))%MOD;
}
int main() {

    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    init(1,n,1);
    for(int i=0; i<m + k; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1) {
            arr[b] = c;
            update(1, n, 1, b, c);

        } else {
            cout << multi(1,n, 1, b, c)%MOD << '\n';
        }
    }
    
    return 0;
}