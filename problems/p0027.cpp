#include<iostream>
#include<iomanip>

#include "../headers/prime.h"

using namespace std;

long compute(int a, int b, int n);
int num_of_primes(int a, int b);
int main(){
	int max_primes = 0;
	int product = 0;
	for(int a = -999; a <= 999; a++){
		for(int b = -1000; b <= 1000; b++){
			int new_n = num_of_primes(a,b);
			if(max_primes < new_n){
				max_primes = new_n;
				product = a*b;
			}
		}
	}
	cout << max_primes << " " << product<< endl;
	return 0;
}

long compute(int a, int b, int n){
	return n*n + a*n + b;
}
int num_of_primes(int a, int b){
	int count = 0;
	int p = 1,n = 0;
	do{
		p = compute(a,b,n);
		n++;
		count++;
		if(p < 1){
			p = 1;
		}
	}while(is_prime(p));
	return count - 1;
}