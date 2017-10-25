#include <iostream>
#include <cassert>

#include "division.h"
#include "utility_for_test.h"

using std::cout;
using std::endl;

void test_gcd_small();
int main(){
	test_gcd_small();
	return 0;
}

void test_gcd_small(){
	cout << "test_gcd_small begin" << endl;
	M_ASSERT((gcd(15,25) == 5),"gcd(15,25)==5");
	M_ASSERT((gcd(2,12) == 2),"gcd(2,12)==2");
	M_ASSERT((gcd(1,13) == 1),"gcd(1,13)==1");
	M_ASSERT((gcd(17,23) == 1),"gcd(17,23)==1");
	cout << "test_gcd_small PASS"  << endl;
}