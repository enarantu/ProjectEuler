#include <cmath>

template <typename T>
bool is_prime(T a){
	if( a == 1){
		return false;
	}
	T limit = sqrt(a) + 1;
	for(T i = 2; i < limit; i += 1){
		if(a%i == 0){
			return false;
		}
	}
	return true;
}
