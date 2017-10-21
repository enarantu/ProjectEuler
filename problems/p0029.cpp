#include <iostream>
using namespace std;
bool duplicate(int a, int b);
int main(){
	int count = 0;
	for(int a = 2 ; a <= 100 ; a++){
		for(int b = 2 ; b <= 100 ; b++){
			if(!duplicate(a,b)){
				count ++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
bool duplicate(int a, int b){
	if( b%2 == 0){
		if(a == 4 or a == 9 or a == 16 or a == 25 or a == 36 or a == 49 or a == 64 or a == 81){
			return true;
		}
	}
	if(b%3 == 0){
		if(a == 8 or a == 27 or a == 64){
			return true;
		}
	}
	if(b%4 == 0){
		if(a == 16 or a == 81){
			return true;
		}
	}
	if(b%5 == 0){
		if(a == 32){
			return true;
		}
	}
	if(b%6 == 0){
		if(a == 64){
			return true;
		}
	}
	return false;
}