#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int alpa[26];
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    queue<char> q;

    for(int i=0; i<skill.size(); i++){
        alpa[skill[i]-'A'] = 1;
        q.push(skill[i]);
    }
    
    for(int i=0; i<skill_trees.size(); i++){
        bool f = true;
        queue<char> tmp = q;
        for(int j=0; j<skill_trees[i].size(); j++){
            if(alpa[skill_trees[i][j]-'A'] == 1){
                if(tmp.front() == skill_trees[i][j]){
                    tmp.pop();
                }
                else{
                    f = false;
                    break;
                }
            }
        }
        if(f) answer++;
    }
    
    return answer;
}