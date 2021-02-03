/*
솔루션 봄
중복제거는 set을 이용
조합을 이용하여 한문자열 합쳐서 체크
*/
#include <string>
#include <vector>
#include <set>
using namespace std;

set<string> s;
vector<string> user;
vector<string> banned;
int visit[10];

void solve(int idx){
    if(idx ==banned.size()){
        string tmp="";
        for(int i=0; i<user.size(); i++){
            if(visit[i]){
                tmp+=user[i];
            }
        }
        s.insert(tmp);
    }
    for(int i=0; i<user.size(); i++){
        bool go = true;
        if(visit[i]) continue;
        if(user[i].size() != banned[idx].size()) continue;
        for(int j=0; j<banned[idx].size(); j++){
            if(banned[idx][j] == '*') continue;
            if(banned[idx][j] != user[i][j]){
                go = false;
                break;
            }
        }
        if(go){
            visit[i] = 1;
            solve(idx+1);
            visit[i] = 0;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    user = user_id;
    banned = banned_id;
    
    solve(0);
    
    answer = s.size();
    return answer;
}