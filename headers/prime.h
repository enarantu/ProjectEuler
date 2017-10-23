#pragma once

#include <cmath>
#include <map>
#include <vector>
#include "utility_for_test.h"

template <typename T>
bool is_prime(T a){
	if( a == 1){
		return false;
	}
	T limit = static_cast<T>(sqrt(a)) + 1;
	for(T i = 2; i < limit; i += 1){
		if(a%i == 0){
			return false;
		}
}
	return true;
}

template<typename T>
void generate_prime_table(std::vector<T>& v, int upperBound){
	for(int i = 2; i <= upperBound; i++){
		if(is_prime(i)){
			v.push_back(i);
		}
	}
}

template<typename T>
void prime_factorization_1(T n, std::map<T,T>& factorization, std::vector<T>& prime_table){
	for(auto i : prime_table){
		if(n % i == 0){
			int count = 0;
			while(n%i == 0){
				count++;
				n /= i;
			}
			factorization[i] = count;
		}	
	}
}