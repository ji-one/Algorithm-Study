// 15903 카드 합체 놀이

#include <iostream>
#include <queue>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    long long sum = 0;
    for(int i=0; i<m; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long c = a+b;
        pq.push(c);
        pq.push(c);
    }

    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
    return 0;
}