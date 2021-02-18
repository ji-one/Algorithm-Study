#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0 ; i<prices.size(); i++){
        int t =0;
        for(int j=i+1; j<prices.size(); j++){
            if(prices[i] > prices[j]) {
                t++;
                break;
            }
            t++;
        }
        answer.push_back(t);
    }
    return answer;
}