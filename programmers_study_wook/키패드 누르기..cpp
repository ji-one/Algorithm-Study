#include <string>
#include <vector>

using namespace std;

int keypad[4][3];
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lx = 3, ly = 0, rx = 3, ry = 2; // 현재 손 위치
    int d = 0;
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            if(numbers[i] == 1){
                answer+='L';
                lx = 0;
                ly = 0;
            }
            if(numbers[i] == 4){
                answer+='L';
                lx = 1;
                ly = 0;
            }
            if(numbers[i] == 7){
                answer+='L';
                lx = 2;
                ly = 0;
            }
        }
        if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0){
            if(numbers[i] == 2){
                if(abs(lx-0) + abs(ly-1) > abs(rx-0) + abs(ry-1)){
                    answer+='R';
                    rx = 0;
                    ry = 1;
                }
                else if(abs(lx-0 + abs(ly-1)) < abs(rx-0) + abs(ry-1)){
                    answer+='L';
                    lx = 0;
                    ly = 1;
                }
                else{
                    if(hand == "right"){
                        answer+='R';
                        rx = 0;
                        ry = 1;
                    }                        
                    else{
                        answer+='L';
                        lx = 0;
                        ly = 1;
                    }
                }
                
                
            }
            if(numbers[i] == 5){
                if(abs(lx-1) + abs(ly-1) > abs(rx-1) + abs(ry-1)){
                    answer+='R';
                    rx = 1;
                    ry = 1;
                }
                else if(abs(lx-1) + abs(ly-1) < abs(rx-1) + abs(ry-1)){
                    answer+='L';
                    lx = 1;
                    ly = 1;
                }
                else{
                    if(hand == "right"){
                        answer+='R';
                        rx = 1;
                        ry = 1;
                    }
                    else{
                        answer+='L';
                        lx = 1;
                        ly = 1;
                    }
                }
                
                
            }
            if(numbers[i] == 8){
                if(abs(lx-2) + abs(ly-1) > abs(rx-2) + abs(ry-1)){
                    answer+='R';
                    rx = 2;
                    ry = 1;
                }
                else if(abs(lx-2) + abs(ly-1) < abs(rx-2) + abs(ry-1)){
                    answer+='L';
                    lx = 2;
                    ly = 1;
                }
                else{
                    if(hand == "right"){
                        answer+='R';
                        rx = 2;
                        ry = 1;
                    }                        
                    else{
                        answer+='L';
                        lx = 2;
                        ly = 1;
                    }
                }
                
                
            }
            if(numbers[i] == 0){
                if(abs(lx-3) + abs(ly-1) > abs(rx-3) + abs(ry-1)){
                    answer+='R';
                    rx = 3;
                    ry = 1;
                }
                else if(abs(lx-3) + abs(ly-1) < abs(rx-3) + abs(ry-1)){
                    answer+='L';
                    lx = 3;
                    ly = 1;
                }
                else{
                    if(hand == "right"){
                        answer+='R';
                        rx = 3;
                        ry = 1;
                    }                        
                    else{
                        answer+='L';
                        lx = 3;
                        ly = 1;
                    }
                }
                
                
            }
        }
        
        if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            if(numbers[i] == 3){
                answer+='R';
                rx = 0;
                ry = 2;
            }
            if(numbers[i] == 6){
                answer+='R';
                rx = 1;
                ry = 2;
            }
            if(numbers[i] == 9){
                answer+='R';
                rx = 2;
                ry = 2;
            }
        }
        
    }
    
    
    return answer;
}