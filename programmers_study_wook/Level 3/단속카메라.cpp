// greedy
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    
    int in = routes[0][0];
    int out = routes[0][1];
    answer=1;
    for(int i=1; i<routes.size(); i++){
        in = routes[i][0];
        if(in > out){
            out = routes[i][1];
            answer++;
        }
    }
    // for(int i=0; i<routes.size(); i++){
    //     cout << routes[i][0] << ", " <<routes[i][1] <<'\n';
    // }
    return answer;
}