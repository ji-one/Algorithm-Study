#include <string>
#include <vector>
#include <iostream>
using namespace std;
string binary(int num){
    string rst = "";
    while(num){
        
        rst = to_string(num%2) + rst;
        num/=2;
    }
    return rst;
}
vector<int> solution(string s) {
    vector<int> answer(2,0);
    int cnt=0;
    int zero=0;
    while(1){
        if(s == "1") break;
        int one = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') one++;
        }
        zero += (s.size() - one);
        s = binary(one);
        cnt++;
    }
    answer[0] = cnt;
    answer[1] = zero;
    return answer;
}