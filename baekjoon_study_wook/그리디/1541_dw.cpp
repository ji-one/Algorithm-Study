// 1541 ÀÒ¾î¹ö¸° °ıÈ£ 
#include <iostream>
#include <stack>
using namespace std;

string str;
stack<string> s;
int main(){
	cin >> str;
	int total = 0;
	string tmp = "";
	bool flag=0;
	for(int i=0; i<str.size(); i++){
		
		if(str[i] >= '0' && str[i] <= '9'){
			tmp+=str[i];
		}	
		else{
			if(flag == 1){
				total -=stoi(tmp);
			}
			else{
				total +=stoi(tmp);
			}
			if(str[i] == '-'){
				flag = 1;	
			}
			tmp.clear();
		}
	}
	if(flag == 1){
		total -=stoi(tmp);
	}
	else{
		total +=stoi(tmp);
	}
	
	cout << total << '\n';
	return 0;
}
