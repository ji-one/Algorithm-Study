// 13549 숨바꼭질 3

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,k;
int dist[100001];
int INF = 100001;
int dx[] = {1, -1};
int dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int currentNode = pq.top().second;
        int currentCost = -pq.top().first;
        pq.pop();
        if(currentNode == k){
            return dist[currentNode];
            
        }
        if(currentCost > dist[currentNode]) continue;
        for(int i=0; i<3; i++){
            int nextNode=0;
            int nextCost=0;

            if(i==2){
                nextNode = currentNode*2;
                nextCost = currentCost;
            }
            else{
                nextNode = currentNode + dx[i];
                nextCost = currentCost + 1;
            }
            if(nextNode<0 || nextNode>100000) continue;
            if(nextCost < dist[nextNode]){
                dist[nextNode] = nextCost;
                pq.push({-nextCost, nextNode});

            }
            
        }

    }
}
int main(){
    cin >> n >> k;
    fill(dist, dist+100001, INF);

    cout << dijkstra(n);
    return 0;
}