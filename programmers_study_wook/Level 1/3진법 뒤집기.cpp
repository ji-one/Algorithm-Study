#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string three(int n){
    string s = "";
    while(n>0){
        s = s + to_string(n%3);
        n/=3;
    }
    return s;
}
int solution(int n) {
    int answer = 0;
    string num = "";
    num = three(n);
    int tmp=1;
    
    for(int i=num.size()-1; i>=0; i--){
        answer += ((num[i]-'0')*tmp);
        tmp*=3;
    }
    return answer;
}