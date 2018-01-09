#include <iostream>
#include <algorithm>

using namespace std;

class Perm{
	int arr[7];
public:
	Perm();
	void set(int x);
	void next();
	int concat();
	bool isPrime();
};

int main(){
	Perm p;
	for(int i = 0; i < 1000000 ; i++){
		if( p.isPrime()){
			cout << p.concat() << endl;
			break;
		}
		p.next();
	}
	return 0;
}
Perm::Perm(){
	for(int i = 0; i < 7 ; i++){
		arr[i] = 7 - i;
	}
}
void Perm::set(int x){
	for(int i = 6; i >= 0; i--){
		arr[i] = x%10;
		x /= 10;
	}
}
void Perm::next(){
	prev_permutation(arr,arr+7);
}
int Perm::concat(){
	int factor = 1, ans = 0;
	for(int i = 6 ; i >= 0 ; i--){
		ans += arr[i]*factor;
		factor *= 10;
	}
	return ans;
}
bool Perm::isPrime(){
	int num = concat();
	for(int i = 2 ; i*i <= num ; i++){
		if(num%i == 0){
			return false;
		}	
	}
	return true;
}