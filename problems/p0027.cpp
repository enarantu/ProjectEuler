#include<iostream>
#include<iomanip>

#include "../headers/prime.h"

using namespace std;

int main(){
	for(int i = 1; i < 200 ; i++){
		cout << setw(6) << i << setw(5) << is_prime(i) << endl;
	}
	return 0;
}
