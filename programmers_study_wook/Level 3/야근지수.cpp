#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    
    long long answer = 0;
    priority_queue<int> pq;
    for(int i =0; i<works.size(); i++){
        pq.push(works[i]);
    }
    while(!pq.empty()){
        if(n==0) break;
        int x = (pq.top()-1);
        pq.pop();
        // 일이 남았으면 다시 큐에 넣기
        if(x != 0 ) pq.push(x);
        n--;
        
    }
    
    if(!pq.empty()){
        while(!pq.empty()){
            answer+=(pq.top()*pq.top());
            // cout << pq.top() << ' ';
            pq.pop();
            
        }
    }
    return answer;
}
