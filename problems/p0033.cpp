#include <iostream>
#include "../headers/division.h"
using namespace std;

class fraction{
	int numerator;
	int denominator;
public:
	fraction(int numerator_in, int denominator_in): numerator(numerator_in),denominator(denominator_in){};
	bool check(){
		int a = numerator/10;
		int b = numerator%10;
		int c = denominator/10;
		int d = denominator%10;
		if((d*numerator == a*denominator and b == c) 
				or 
				(c*numerator == b*denominator and a == d)){
			return true;
		}
		return false;
	}
	void print(int& n , int& d){
		n *= numerator;
		d *= denominator;
	}
};
int main(){
	int n = 1;
	int d = 1;
	for(int i = 10; i <= 99; i++){
		for(int j = i+1; j <= 99; j++){
			fraction f = fraction(i,j);
			if(f.check()){
				f.print(n,d);
			}
		}
	}
	int g = gcd(n,d);
	cout << d/ g << endl;
	return 0;
}