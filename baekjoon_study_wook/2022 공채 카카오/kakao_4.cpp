#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MAX=0;
vector<int> temp(11);

int cal(vector<int>& lion, vector<int>& apeach) {
    int lionScore = 0;
    int apeachScore= 0;
    for(int i=0; i<11; i++) {
        if(lion[i] == 0 && apeach[i] == 0) continue;
        if(lion[i] > apeach[i]) {
            lionScore += (10-i);
        } else {
            apeachScore += (10-i);
        }
    }
    return lionScore - apeachScore;
}

vector<int> cmp(vector<int>& lion) {
    for(int i=10; i>=0; i--) {
        if(lion[i] == temp[i]) continue;
        if(lion[i] > temp[i])
            return lion;
        else
            return temp;
    }
    return temp;
}
void dfs(int idx, int cnt, int n, vector<int>& lion, vector<int>& apeach) {

    if(cnt == n) {

        int diff = cal(lion, apeach);
        if(MAX <= diff) {
            if(MAX == diff) {
                temp = cmp(lion);
            } else {
                MAX = diff;
                temp = lion;
            }

        }
        return ;
    }

    for(int i=idx; i<11; i++) {
        lion[i]++;
        dfs(i, cnt+1, n, lion, apeach);
        lion[i]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> lion(11, 0);

    dfs(0, 0, n, lion, info);
    if(MAX==0){
        return {-1};
    }
    cout << MAX<<'\n';

    answer = temp;
    return answer;
}