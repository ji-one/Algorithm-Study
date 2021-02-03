#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

map<string,int> m;

void dfs(int cnt, int x, int set, string order, string s){
    if(cnt == set){
        // cout << s << '\n';
        m[s]++;
    }
    for(int i=x; i<order.size(); i++){
        dfs(cnt+1, i+1, set, order, s+order[i]);
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<string> v;
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
    }    
    for(int i=0; i<course.size(); i++){
        m.clear();
        for(int j=0; j<orders.size(); j++){
            dfs(0,0,course[i], orders[j], "");
        }
        int max_v=2;
        for(auto it = m.begin(); it!=m.end(); it++){
            if(max_v < it->second){
                max_v = it->second;
            }
        }
        for(auto it = m.begin(); it!=m.end(); it++){
            if(max_v == it->second){
                answer.push_back(it->first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    
    return answer;
}