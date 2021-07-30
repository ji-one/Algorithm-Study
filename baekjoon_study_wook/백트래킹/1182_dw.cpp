// 1182 부분수열의 합

#include <iostream>
#include <vector>
using namespace std;

int n,s, rst;
int arr[21];
vector<int> v;

void dfs(int idx) {
    if(v.size() > 0) {
        int sum = 0;
        for(int i=0; i<v.size(); i++) {
            sum += v[i];
        }
        if(sum == s) {
            rst++;
        }
    }

    for(int i=idx; i<n; i++) {
        v.push_back(arr[i]);
        dfs(i+1);
        v.pop_back();
    }
}
int main() {
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    dfs(0);
    cout << rst;
    return 0;
}