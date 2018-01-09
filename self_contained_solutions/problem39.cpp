#include <iostream>
#include <cmath>

using namespace std;
int main(){
	int max_c = 0;
	int max_num = 0;
	for(int p = 5 ; p <= 1000 ; p++){
		int ct = 0;
		for(int c = static_cast<int>(p/sqrt(6)) ; c*2 < p ; c++ ){
			for(int b = static_cast<int>(c/sqrt(2)); b < c ; b++){
				int a = p - c - b;
				if(a < b and b < c and c*c == b*b + a*a){
					ct++;
				}
			}
		}
		if( max_c < ct){
			max_c = ct;
			max_num = p;
		}
	} 
	cout << max_num << endl;
	return 0;
}
