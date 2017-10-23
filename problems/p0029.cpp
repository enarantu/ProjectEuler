#include <iostream>
#include <map>
#include <vector>

#include "../headers/prime.h"

using namespace std;

class Number{
	map<int,int> factorization;
public:
	Number(int base, int power, vector<int> primes){
		prime_factorization_1(base,factorization,primes);
		for(auto &i : factorization){
			i.second *= power;
		}
	}
	bool isEqual(map<int,int>* f){
		if(factorization.size() != f->size()){
			return false;
		}
		for(auto &i : factorization){
			if(f->find(i.first) == f->end()){
				return false;
			}
			else{
				if((*f)[i.first] != i.second  ){
					return false;
				}
			}
		}
		return true;
	}
	map<int,int> * getFactorization(){
		return &factorization;
	}
};
int main(){
	vector<int> primes;
	generate_prime_table(primes,100);
	vector<Number> unique_numbers;
	for(int i = 2; i <= 100 ; i++){
		for(int j = 2; j <= 100 ; j++){
			Number n = Number(i,j,primes);
			bool is_diff = true;
			for(auto &u : unique_numbers){
				if(u.isEqual(n.getFactorization())){
					is_diff = false;
					break;
				}
			}
			if(is_diff){
				unique_numbers.push_back(n);
			}
		}
	}
	cout << unique_numbers.size() << endl;
	return 0;
}