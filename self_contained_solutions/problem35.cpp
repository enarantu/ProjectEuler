#include <iostream>
#include <deque>
using namespace std;
class Num{
	deque<int> digits;
public:
	Num(int i);
	void rotate();
	int toNumber();
};
bool isPrime(int n);
int  numDigit( int n);
int main(){
	int total = 0;
	for(int i = 2 ; i < 1000000 ; i++){
		Num n(i);
		bool ans = true;
		for(int j = 0 ; j < numDigit(i) ; j++){
			if(!isPrime(n.toNumber())){
				ans = false;
				break;
			}
			n.rotate();
		}
		if(ans){
			total++;
		}
	}
	cout << total << endl;
	return 0;
}
int  numDigit( int n){
	int ans = 0; 
	while(n > 0){
		n /= 10;
		ans ++;
	}
	return ans;
}
bool isPrime(int n){
	for(int i = 2 ; i*i <= n ; i++){
		if( n%i == 0){
			return false;
		}
	}
	return true;
}
Num::Num(int i){
	while(i > 0){
		digits.push_back(i%10);
		i /= 10;
	}
}
int Num::toNumber(){
	int factor = 1;
	int ans = 0;
	for(auto i : digits){
		ans += i*factor;
		factor 	*= 10;
	}
	return ans;
}
void Num::rotate(){
	auto i = digits.back();
	digits.pop_back();
	digits.push_front(i);
}