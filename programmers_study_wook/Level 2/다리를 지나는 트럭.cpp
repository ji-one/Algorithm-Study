#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> t;
    queue<int> q;
    
    q.push(truck_weights[0]);
    t.push_back(bridge_length);
    int sum = q.front();
    answer++;
    int idx = 1;
    while(!q.empty()){
        answer++;
        
        for(int i=0; i<t.size(); i++){

            t[i]--;
        }
        if(t[0] == 0 && t.size() > 0){
            sum -= q.front();
            q.pop();
            t.erase(t.begin());
        }
        if(sum + truck_weights[idx] <= weight && idx <truck_weights.size()){
            q.push(truck_weights[idx]);
            sum += truck_weights[idx];
            t.push_back(bridge_length);
            idx++;
        }
    }
    return answer;
}
