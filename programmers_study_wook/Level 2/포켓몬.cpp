#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> us;
int solution(vector<int> nums)
{
    int n = nums.size();
    int answer = 0;
    for(int i=0; i<n; i++){
        us.insert(nums[i]);
    }
    if(us.size() < n/2)
        answer = us.size();
    else
        answer = n/2;
    return answer;
}