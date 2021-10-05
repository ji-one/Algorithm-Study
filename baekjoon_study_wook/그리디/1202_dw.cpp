// 1202 보석 도둑

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,k;
vector<int> bag;
vector<pair<int, int>> jewels;

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int m, v;
        cin >> m >> v;
        jewels.push_back({m, v});
    }

    for(int i=0; i<k; i++) {
        int c;
        cin >> c;
        bag.push_back(c);
    }

    sort(jewels.begin(), jewels.end());
    sort(bag.begin(), bag.end());

    long long sum = 0;
    int idx= 0; // 보석 인덱스

    priority_queue<int> pq; // 작은거 부터 가방에 넣을 수 있는 보석 가격
    for(int i=0; i<k; i++) {    // 가방 인덱스
        
        while(idx<n && jewels[idx].first <= bag[i]) {
            pq.push(jewels[idx].second);
            idx++;
        }

        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;
    return 0;
}