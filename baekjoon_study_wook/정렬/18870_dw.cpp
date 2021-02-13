// 18870 좌표 압축

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second<b.second;
}
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back({tmp, i});
    }

    sort(v.begin(), v.end());
    int idx = 0;
    int temp = v[0].first;
    v[0].first = idx;
    for(int i=1; i<n; i++){
        if(temp == v[i].first){ // 크기가 같으면 같은 인덱스
            v[i].first = idx;
            continue;
        }
        // 크기가 다르면 인덱스를 +1
        idx++;
        temp = v[i].first;
        v[i].first = idx;
    }
    sort(v.begin(), v.end(), cmp); // 원래 순서대로 재배열
    for(int i=0; i<n; i++){
        cout << v[i].first << ' ';
    }
    return 0;
}