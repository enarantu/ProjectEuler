#include <iostream>
#include <cassert>

#include "prime.h"
#include "utility_for_test.h"

using namespace std;

void prime_table_generation_test_1();
int main(){
	prime_table_generation_test_1();
	cout << "all prime generation tests PASS" << endl;
	return 0;
}
void prime_table_generation_test_1(){
	cout << "prime_table_generation_test_1 start" << endl;
	vector<int> primes;
	int upperbound = 1000;
	generate_prime_table(primes,upperbound);
	M_ASSERT( (primes[0]==2), "first prime should be 2");
	M_ASSERT( (primes[1]==3), "second prime should be 3");
	M_ASSERT( (primes[2]==5), "third prime should be 5");
	M_ASSERT( (primes[167] == 997), "167th prime is 997");
	cout << "prime_table_generation_test_1 SUCCESS" << endl;
}