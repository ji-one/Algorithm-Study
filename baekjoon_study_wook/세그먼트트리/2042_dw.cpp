// 2042 구간 합 구하기

#include <iostream>

using namespace std;

int n, m, k;
long long arr[1000001];
long long tree[1000001*4];

long long init(int start, int end, int node) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end)/2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

long long sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int changeIndex, long long diff) {
    if(changeIndex < start || changeIndex > end) return ;
    tree[node] += diff;
    if(start == end) return ;

    int mid = (start + end)/2;
    update(start, mid, node*2, changeIndex, diff);
    update(mid+1, end, node*2+1, changeIndex, diff);
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    // 구간합 세그먼트 트리 생성
    init(1, n, 1);

    for(int i=0; i<m+k; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            int b;
            long long c;
            cin >> b >> c;
            long long diff = c - arr[b];
            update(1, n, 1, b, diff);
            arr[b] = c;
        } else {
            int b,c;
            cin >> b >> c;
            cout << sum(1, n, 1, b, c) << '\n';
        }

    }
    return 0;
}