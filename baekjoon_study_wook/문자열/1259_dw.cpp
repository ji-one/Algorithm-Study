// 1259 팬린드롬

#include <iostream>
#include <string>
using namespace std;

int main(){
    string n="";
    while(1){
        cin >> n;
        if(n == "0") break;
        bool c = true;
        int l = n.size();
        for(int i=0; i<l/2; i++){
            if(n[i] != n[l-i-1]){
                c = false;
                break;
            }
                
        }
        if(c) cout << "yes\n";
        else  cout << "no\n";
    }
    return 0;
}