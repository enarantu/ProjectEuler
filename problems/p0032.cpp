#include <iostream>
#include <set>

using std::set;
using std::cout;
using std::endl;

bool check(int a, int b);
int num_digit(int n);
void get_digits(int n, set<int>& digits);
int main(){
	set<int> pandigital;
	for(int a = 10; a <= 99; a++){
		for(int b = 100; b <= 999; b++){
			if(check(a,b)){
				pandigital.insert(a*b);
			}
		}
	}
	for(int a = 1; a <= 9 ; a++){
		for(int b = 1000; b <= 9999; b++){
			if(check(a,b)){
				pandigital.insert(a*b);
			}
		}
	}
	int sum = 0;
	for(auto &i : pandigital){
		sum += i;
	}
	cout << sum << endl;
	return 0;
}
bool check(int a, int b){
	set<int> digits;
	
	if(num_digit(a) + num_digit(b) + num_digit(a*b) != 9){
		return false;
	}
	get_digits(a,digits);
	get_digits(b,digits);
	get_digits(a*b,digits);
	
	if(digits.size() != 9){
		return false;
	}
	else if(digits.find(0) != digits.end()){
		return false;
	}
	else{
		return true;
	}
}

void get_digits(int n, set<int>& digits){
	while(n > 0){
		digits.insert(n%10);
		n /= 10;
	}
}
int num_digit(int n){
	int count = 0;
	while ( n > 0){
		n /= 10;
		count ++;
	}
	return count;
}