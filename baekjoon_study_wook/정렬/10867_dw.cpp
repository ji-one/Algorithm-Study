// 10867 중복 빼고 정렬

#include <iostream>
#include <set>
using namespace std;

set<int> s;
int n;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    for(set<int>::iterator it = s.begin(); it!= s.end(); it++){
        cout << *it << ' ';
    }
    return 0;
}