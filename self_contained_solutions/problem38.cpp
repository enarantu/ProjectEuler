#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;
class Perm{
	int arr[9];
public:
	Perm();
	void set(int x);
	void next();
	int concat();
	bool is45();
	bool is333();
	bool is2223();
	bool is12222();
	bool is();
};

int main(){

	Perm pp;
	bool no_ans = true;
	while(no_ans){
		if(pp.is()){
			no_ans = false;
			cout << pp.concat() << endl;
		}
		pp.next();
	}
	return 0;
}
Perm::Perm(){
	for(int i = 0; i < 9 ; i++){
		arr[i] = 9 - i;
	}
}
void Perm::set(int x){
	for(int i = 8; i >= 0; i--){
		arr[i] = x%10;
		x /= 10;
	}
}
void Perm::next(){
	prev_permutation(arr,arr+9);
}
int Perm::concat(){
	int factor = 1, ans = 0;
	for(int i = 8 ; i >= 0 ; i--){
		ans += arr[i]*factor;
		factor *= 10;
	}
	return ans;
}
bool Perm::is45(){
	int p1 = 0, p2 = 0, factor = 1;
	for(int i = 3; i >= 0; i--){
		p1 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	for(int i = 8; i >= 4; i--){
		p2 += arr[i]*factor;
		factor *= 10;
	}
	return p1*2 == p2;
}
bool Perm::is333(){
	int p1 = 0, p2 = 0, p3 = 0, factor = 1;
	for(int i = 8; i >= 6 ; i--){
		p3 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	for(int i = 5; i >= 3 ; i--){
		p2 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	for(int i = 2; i >= 0 ; i--){
		p1 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	return p1*2 == p2 and p1*3 == p3;
}
bool Perm::is2223(){
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0, factor = 1;
	for(int i = 1; i >= 0; i--){
		p1 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	for(int i = 3; i >= 2; i--){
		p2 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	for(int i = 5; i >= 4; i--){
		p3 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	for(int i = 8; i >= 6; i--){
		p4 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	return p1*2 == p2 and p1*3 == p3 and p1*4 == p4;
}
bool Perm::is12222(){
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, factor = 1;
	p1 = arr[0];
	for(int i = 2; i >= 1 ; i--){
		p2 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	for(int i = 4; i >= 3 ; i--){
		p3 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	for(int i = 6; i >= 5 ; i--){
		p4 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1;
	for(int i = 8; i >= 7 ; i--){
		p5 += arr[i]*factor;
		factor *= 10;
	}
	factor = 1; 
	return p1*2 == p2 and p1*3 == p3 and p1*4  == p4 and p1*5 == p5;
}
bool Perm::is(){
	return is45() or is333() or is12222() or is2223();
}