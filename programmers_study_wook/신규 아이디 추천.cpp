#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for(int i=0; i<new_id.size(); i++){
        if(new_id[i] >='A' && new_id[i] <='Z'){
            new_id[i] = new_id[i] + ('a'-'A');
            
        }
        
    }
    // 2단계
    for(int i=0; i<new_id.size(); i++){
        if((new_id[i]>='a' && new_id[i]<='z')) continue;
            
        if((new_id[i] >='0' && new_id[i]<='9')) continue;  
        
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') continue;
        new_id.erase(new_id.begin()+i);
        i--;
    }
    
    // 3단계
    for(int i=0; i<new_id.size();i++){
        if(new_id[i] == '.'){
            int x=i;
            int cnt=1;
            while(1){
                i++;
                if(new_id[i] != '.') break; 
                
                cnt++;
            }
            if(cnt>=2){
                new_id.erase(new_id.begin() + x+1, new_id.begin() + i);
                i = x;
            }
        }
    }
    // 4단계
    if(new_id[0] == '.') new_id.erase(new_id.begin());
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.begin() + new_id.size()-1); 
    
    // 5단계
    if(new_id.size() == 0) new_id="a";
    
    // 6단계
    if(new_id.size()>=16) new_id = new_id.substr(0,15);
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.begin() + new_id.size()-1); 
    
    // 7단계 
    while(new_id.size()<=2){
        new_id += new_id[new_id.size()-1];
    }
    
    answer = new_id;
    return answer;
}