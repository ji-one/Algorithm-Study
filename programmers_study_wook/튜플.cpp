#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

unordered_map<int, int> um;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second> b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    string tmp = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] >='0' && s[i] <='9'){
            tmp+=s[i];
        }
        else if(tmp.size() > 0 && (s[i] == ',' || s[i] == '}')){
            um[stoi(tmp)]++;
            tmp = "";
        }
    }
    vector<pair<int,int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].first);
    }
    return answer;
}