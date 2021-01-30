// 카카오 2018
#include <string>
#include <iostream>
#include <vector>
using namespace std;


string change(string s){
    string tmp="aa";
    for(int i=0; i<2; i++){
        if(s[i] >= 'a' && s[i] <='z')
            tmp[i] = s[i]-('a'-'A');
        else
            tmp[i] = s[i];
    }
    
    return tmp;
}

bool checkAlpa(string s){
    for(int i=0; i<s.size(); i++){
        if(!(s[i]>='A' && s[i]<='Z'))
            return false;
    }
    return true;
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    
    for(int i=0; i<str1.size(); i++){
        string tmp= change(str1.substr(i,2));
        if(tmp.size() != 2) continue;
        else if(!checkAlpa(tmp)) continue;
        v1.push_back(tmp);
    }
    
    for(int i=0; i<str2.size(); i++){
        string tmp= change(str2.substr(i,2));
        if(tmp.size() != 2) continue;
        else if(!checkAlpa(tmp)) continue;
        v2.push_back(tmp);
    }
    
    if(v1.size() == 0 && v2.size() == 0){
        answer=65536;
    }
    else {
        double sum = v1.size() + v2.size();
        double inter = 0;
        for(int i=0; i<v1.size(); i++){
            for(int j=0; j<v2.size(); j++){
                if(v1[i] == v2[j]){
                    v1.erase(v1.begin()+i);
                    v2.erase(v2.begin()+j);
                    i--;
                    j--;
                    inter++;
                }
            }
        }
        sum -=inter;
        // cout << inter << ' ' << sum;
        answer = (inter/sum)*65536;
    }
    return answer;
}