#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int r = arr1.size();
    int c = arr2[0].size();
    int m = arr1[0].size();
    
    vector<vector<int>> answer(r, vector<int>(c,0));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            for(int k=0; k<m; k++){
                answer[i][j] += (arr1[i][k]*arr2[k][j]);
            }
            
        }
    }
    return answer;
}