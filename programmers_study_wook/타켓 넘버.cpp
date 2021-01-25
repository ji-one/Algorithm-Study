#include <string>
#include <vector>
using namespace std;

int answer=0;
void dfs(int cnt, int sum, vector<int> numbers, int target){
    
    if(cnt == numbers.size()){
        if(sum == target) answer++;
        return ;
    }
    
    dfs(cnt+1,sum+numbers[cnt],numbers,target);
    dfs(cnt+1,sum-numbers[cnt],numbers,target);
    
    return ;
}
int solution(vector<int> numbers, int target) {
    
    dfs(0,0,numbers,target);
    return answer;
}