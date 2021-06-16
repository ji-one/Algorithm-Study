// 2357 최솟값과 최댓값

#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1987654321
using namespace std;
int n, m;
int arr[100001];
int minTree[400001];
int maxTree[400001];

void init(int start, int end, int node) {
    if(start == end) {
        minTree[node] = maxTree[node]= arr[start];
        return ;
    
    }
    int mid = (start+end)/2;
    init(start,mid,node*2);
    init(mid+1,end,node*2+1);
    
    minTree[node] = min(minTree[node*2], minTree[node*2+1]);
    maxTree[node] = max(maxTree[node*2], maxTree[node*2+1]);
    return ;
}

int maxInit(int start, int end, int node) {
    if(start == end) return maxTree[node] = arr[start];
    int mid = (start+end)/2;
    return maxTree[node] = max(maxInit(start,mid,node*2), maxInit(mid+1,end,node*2+1));
}

pair<int, int> selectMinMax(int start, int end, int node, int left, int right) {
    if(start > right || end < left) return {MAX, 0};
    if(start >= left && end <= right) return {minTree[node], maxTree[node]};
    int mid = (start + end)/2;
    pair<int, int> l, r;
    l = selectMinMax(start, mid, node*2, left, right);
    r = selectMinMax(mid+1, end, node*2+1, left, right);
    return {min(l.first, r.first), max(l.second, r.second)};
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    init(1, n, 1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a>> b;
        pair<int, int> res = selectMinMax(1, n, 1, a, b);

        cout << res.first << ' ' << res.second <<'\n';

    }
    return 0;
}