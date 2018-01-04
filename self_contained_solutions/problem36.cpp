#include <iostream>
#include <string>

using namespace std;

class Num{
	int number;
	string dec;
	string bin;
public:
	Num(int x);
	bool isDoublePalindome();
};

int main(){
	long long sum = 0;
	for(long long i = 1 ; i < 1000000 ; i++){
		Num n(i);
		if(n.isDoublePalindome()){
			sum += i;
		}
	}

	cout << sum << endl;
	
	return 0;
}
Num::Num(int x){
	dec = to_string(x);
	number = x;

	while (x > 0){
		bin.push_back( 48 + x%2 );
		x /= 2;
	}

}

bool Num::isDoublePalindome(){
	bool ans = true;
	for(size_t i = 0 ; i <= dec.size()/2 ; i++){
		size_t opp = dec.size() - i - 1;
		if(dec[i] != dec[opp]){
			ans = false;
			break;
		}
	}
	if(ans){
		for(size_t i = 0 ; i <= bin.size() ; i++){
			size_t opp = bin.size() - i - 1;
			if(bin[i] != bin[opp]){
				ans = false;
				break;
			}
		}
	}
	return ans;
}