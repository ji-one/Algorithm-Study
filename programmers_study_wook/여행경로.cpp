#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> answer;
vector<string> tmp;

int visit[10000];

bool cmp(vector<string> a, vector<string> b){
    if(a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0]<b[0];
}


void dfs(int v, vector<vector<string>> tickets){
    string next = tickets[v][1];
    if(tmp.size() == tickets.size()){
        tmp.push_back(next);
        
        answer.assign(tmp.begin(), tmp.end());
        tmp.pop_back();
        return ;
    }
    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0] == next && visit[i] == 0){
            visit[i] = 1;
            tmp.push_back(tickets[i][0]);
            dfs(i, tickets);
            if(answer.size() != 0)
                break;
            visit[i] = 0;
            tmp.pop_back();
        }
    }
    
    return ;
}


vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), cmp);
    // for(int i=0; i<tickets.size(); i++){
    //     cout << tickets[i][0] << ' ' << tickets[i][1] << '\n';
    // }
    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0] == "ICN"){
            tmp.push_back(tickets[i][0]);
            visit[i] = 1;
            dfs(i, tickets);
            tmp.pop_back();
            visit[i] = 0;
            if(answer.size() != 0)
                break;
        }
    }
    
    return answer;
}