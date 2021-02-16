#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int n;
int visit[51];
int answer = 0;

bool Check(string a, string b){
    int dif=0;
    for(int i=0; i<n; i++){
        if(a[i] != b[i])
            dif++;
    }
    if(dif==1) return true;
    else    return false; 
}
void bfs(string begin, string target, vector<string> words){
    
    queue<int> q;
    q.push(words.size()-1);
    
    while(!q.empty()){
        int c = q.front();
        q.pop();
        if(words[c] == target){
            answer = visit[c];
            break;
        }
        for(int i=0; i<words.size(); i++){
            if(visit[i]==0 && Check(words[c],words[i])){
                visit[i] = visit[c]+1;
                q.push(i);
            }
        }
    }
    return ;
}
int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    n = begin.size();
    bfs(begin, target, words);
    return answer;
}