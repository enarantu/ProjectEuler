#include <vector>

//REQUIRES v to be a pointer to empty vector
//EFFECTS  returns list of divisors of num excluding 1 and itself
//MODIFIES v
template<typename T>
void list_divisors_0(T num, std::vector<T> * v){
    for(T i = 2 ; i*2 <= num ; i ++){
        if(num%i == 0){
            v->push_back(i);
        }
    }
}

template<typename T>
T gcd(T a, T b){
	if(a == 0 or b == 0){
		return a + b;
	}
	else if(a > b){
		return gcd(a%b,b);
	}
	else{
		return gcd(a,b%a);
	}
}