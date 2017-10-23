#include <iostream>

using namespace std;
int power5(int x);
int power5sum(int n);
int main(){
	int sum = 0;
	for(int i = 2 ; i < 9999999; i++){
		if(power5sum(i) == i){
			sum += i;
			cout << i << endl;
		}
	}
	cout << sum << endl;
	return 0;
}
int power5(int x){
	return x*x*x*x*x;
}
int power5sum(int n){
	int sum = 0;
	while(n > 0){
		sum += power5(n%10);
		n /= 10; 
	}
	return sum;
}