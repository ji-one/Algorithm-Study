// 크로아티아 알파벳2941 
#include <iostream>

using namespace std;

string str;

int main(){
	cin >> str;
	
	int cnt =0;
	for(int i=0; i<str.size(); i++){
		if(str[i] == '-' || str[i] == '=') continue;
		if(str[i] == 'l' && str[i+1] == 'j') i++;
		if(str[i] == 'n' && str[i+1] == 'j') i++;
		if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') i++;
		cnt++;
	}
	
	cout << cnt << '\n';
	return 0;
}
