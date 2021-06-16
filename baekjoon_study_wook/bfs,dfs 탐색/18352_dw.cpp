// 18352 특정 거리의 도시 찾기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k ,x;
vector<int> map[300001];
vector<int> v;
int visit[300001];

void bfs(int node) {
    queue<pair<int, int>> q;
    q.push({node, 0});
    visit[node] = 1;

    while(!q.empty()) {
        int currentNode = q.front().first;
        int currentDist = q.front().second;
        q.pop();

        if(currentDist == k) {
            v.push_back(currentNode);
            continue;
        }
        for(int i=0; i<map[currentNode].size(); i++) {
            int nextNode = map[currentNode][i];
            if(!visit[nextNode]) {
                visit[nextNode] = 1;
                q.push({nextNode, currentDist + 1});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> x;
    for(int i=0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        map[from].push_back(to);

    }

    bfs(x);

    if(v.size() == 0) {
        cout << -1;
    } else {
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++) {
            cout << v[i] << '\n';
        }
    }
    return 0;
}