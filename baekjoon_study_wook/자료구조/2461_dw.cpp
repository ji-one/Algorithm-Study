// 2461 대표 선수

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 2100000000
#define MIN -2100000000


using namespace std;

int n,m;
priority_queue<int, vector<int>, greater<int>> _class[1001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int person = 0;
            cin >> person;
            _class[i].push(person);
        }
    }

    
    int answer = MAX;
    int minIndex;
    bool exit = false;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    
    int maxValue = MIN;
    for(int i=0; i<n; i++) {
        pq.push({_class[i].top(),i});
        maxValue = max(maxValue, _class[i].top());
    }
    minIndex = pq.top().second;
    answer = min(answer, maxValue - pq.top().first);
    _class[minIndex].pop();
    pq.pop();

    while(1) {

        /*
        // 각 반의 top 을 비교
        for(int i=0; i<n; i++) {
            if(maxValue < _class[i].top()) {
                maxValue = _class[i].top();
            }
            if(minValue > _class[i].top()) {
                minValue = _class[i].top();
                minIndex = i;
            }
        }
        */
        maxValue = max(maxValue, _class[minIndex].top());
        pq.push({_class[minIndex].top(), minIndex});
        
        // 최대값에서 최소값 빼기
        answer = min(answer, maxValue - pq.top().first);
        minIndex = pq.top().second;
        // cout << maxValue << ' ' << pq.top().first << ' ' << answer <<'\n';
        // 가장 작은 인덱스 pop
        _class[minIndex].pop();
        pq.pop();

        // 하나의 큐가 empty면 그만
        for(int i=0; i<n; i++) {
            if(_class[i].empty()) {
                exit = true;
                break;
            }
        }
        if(exit) {
            break;
        }
    }
    cout << answer;
    return 0;
}