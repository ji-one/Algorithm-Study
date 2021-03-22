// 2019 순회강연
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int visit[10001];

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
int main(){
    cin >> n;
    for(int i=0 ;i<n; i++){
        int p, d;
        cin >> p >> d;
        v.push_back({p,d});
    }

    sort(v.begin(), v.end(), cmp);
    
    int pay = 0;
    for(int i=0 ;i<n; i++){
        int day = v[i].second;
        if(!visit[day]){
            pay += v[i].first;
            visit[day] = 1;
        }
        else{
            day--;
            while(day>0){
                if(!visit[day]){
                    visit[day] = 1;
                    pay+=v[i].first;
                    break;
                };
                day--;
            }
        }
        
    }

    cout << pay;
    return 0;
}