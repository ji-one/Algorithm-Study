// 1543 문서검색
#include <iostream>

using namespace std;

string str, s;
int main(){
	getline(cin,str,'\n');
	getline(cin,s,'\n');
	
	int rst=0;
	for(int i=0; i<str.size(); i++){
		if(s == str.substr(i,s.size())){
			rst++;
			i = i+s.size()-1;
		}
	}
	cout << rst;
	return 0;
} 
