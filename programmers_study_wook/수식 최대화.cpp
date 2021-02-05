#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> num;
vector<char> oper;
char op[] = {'-', '+', '*'};
vector<char> v;
int visit[3];

long long max_val;
void dfs(int cnt){
    if(cnt == 3){
        vector<long long> tmp1 = num;
        vector<char> tmp2 = oper;

        for(int j=0; j<v.size(); j++){
            for(int i=0; i<tmp2.size(); i++){
                if(v[j] == tmp2[i]){
                    if(tmp2[i] == '-'){
                        tmp1[i] = tmp1[i] - tmp1[i+1];
                    }
                    if(tmp2[i] == '+'){
                        tmp1[i] = tmp1[i] + tmp1[i+1];
                    }
                    if(tmp2[i] == '*'){
                        tmp1[i] = tmp1[i] * tmp1[i+1];
                    }
                    tmp1.erase(tmp1.begin() + i+1);
                    tmp2.erase(tmp2.begin() + i);
                    i--;
                }
            }
        }
        max_val = max(max_val, abs(tmp1[0]));
        return ;
    }
    for(int i=0; i<3; i++){
        if(visit[i]) continue;
        visit[i] = 1;
        v.push_back(op[i]);
        dfs(cnt+1);
        visit[i] = 0;
        v.pop_back();
    }
    
    return ;
}
long long solution(string expression) {
    long long answer = 0;
    string tmp="";
    for(int i=0; i<expression.size(); i++){
        if(expression[i] == '-' || expression[i] == '+' || expression[i] == '*'){
            num.push_back(stoi(tmp));
            oper.push_back(expression[i]);
            tmp = "";
        }
        else{
            tmp+=expression[i];
        }
        if(i == expression.size() - 1){
            num.push_back(stoi(tmp));
        }
        
    }
    
    dfs(0);
    answer = max_val;
    return answer;
}