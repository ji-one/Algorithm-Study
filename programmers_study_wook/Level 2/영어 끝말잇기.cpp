#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> um;
    um[words[0]]++;
    for(int i=1; i<words.size(); i++){
        um[words[i]]++;
        if(um[words[i]] == 2 || (words[i-1].back() != words[i].front())){
            answer.push_back(i%n + 1);
            answer.push_back(i/n + 1);
            break;
        }
        if(i==words.size()-1){
            answer.push_back(0);
            answer.push_back(0);
        }
    }
    return answer;
}