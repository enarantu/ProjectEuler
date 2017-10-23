#include <iostream>
#include <cassert>

#include "prime.h"
#include "utility_for_test.h"

using namespace std;

void factorization_1_test();
int main(){
	factorization_1_test();
	cout << "all factorization tests PASS" << endl;
	return 0;
}
void factorization_1_test(){
	cout << "factorization 1 test start" << endl;
	vector<int> primes;
	int upperbound = 100;
	generate_prime_table(primes,upperbound);	
	int n = 72;
	map<int, int > n_fact;
	prime_factorization_1(n,n_fact,primes);
	M_ASSERT((n_fact[2]==3),"2 to the 3rd should be in the factorization");
	M_ASSERT((n_fact[3]==2),"3 squared should be in the factorization");
	M_ASSERT((n_fact.size() == 2),"there should be only 2 factors");

	cout << "factorization 1 test SUCCESS" << endl;
}