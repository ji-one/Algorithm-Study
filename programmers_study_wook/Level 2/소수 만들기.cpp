#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int n;
int answer;
bool isPrime(int num){
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0)
            return false;
    }
    return true;
}
void dfs(int cnt, int x, int sum, vector<int>& nums){
    if(cnt == 3){
        if(isPrime(sum)){
            answer++;
        }
        return ;
    }
    
    
    for(int i=x; i<n; i++){
        dfs(cnt+1, i+1, sum + nums[i], nums);
    }
}
int solution(vector<int> nums) {
    
    n = nums.size();
    dfs(0,0,0,nums);
    return answer;
}