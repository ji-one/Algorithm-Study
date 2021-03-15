// 7785 회사에 있는 사람
#include <iostream>
#include <set>
#include <string>

using namespace std;

int n;
set<string> s;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string name, _in_out;
        cin >> name >> _in_out;
        if(_in_out == "enter"){
            s.insert(name);
        }
        else{
            s.erase(name);
        }
    }
    set<string>::reverse_iterator rit;
    for(rit = s.rbegin(); rit!=s.rend(); ++rit)
        cout << *rit << '\n';
    return 0;
}