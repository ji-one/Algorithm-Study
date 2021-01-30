#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = s.length();
    int len = s.length();
    int cs_len = 0;
    stack<string> stk;
    
    for(int k = 1; k < len - 1 ; k++){ // k: 자르는 단위
        string cs = ""; // compressed string
        for(int i = 0; i < len; i += k){
            string cur = "";
            for(int j = i; j <  i + k && j < len; j++){ // 문자열 k길이만큼 잘라용~
                cur += s[j];
            }
            if(!stk.empty() && stk.top() != cur){
                if(stk.size() > 1) 
                    cs += to_string(stk.size());
                cs += stk.top();
                while(!stk.empty()) 
                    stk.pop(); 
            }
            stk.push(cur);
        }
        if(!stk.empty()){
            if(stk.size() > 1) 
                    cs += to_string(stk.size());
                cs += stk.top();
                while(!stk.empty()) 
                    stk.pop(); 
        }
        cs_len = cs.length();
        answer = min(answer, cs_len);
    }
    
    return answer;
}