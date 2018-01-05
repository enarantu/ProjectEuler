#include <iostream>
#include <deque>

using namespace std;

class Num{
	int n;
	deque<int> digits;
public:
	Num(int x):n(x){};
	void removeRightDigit();
	void removeLeftDigit();
	void resetDeque();
	int  dequeToInt();
	size_t  dequeSize();
};

bool is_prime(int n);

int main(){
	int answer = 0;
	for(int i = 10 ; i < 2000000 ; i++){
		Num n(i);
		n.resetDeque();
		bool ans = true;
		while(n.dequeSize() > 0){
			if(!is_prime(n.dequeToInt())){
				ans = false;
				break;		
			}
			n.removeLeftDigit();
		}
		n.resetDeque();
		if(ans){	
			while(n.dequeSize() > 0){
				if(!is_prime(n.dequeToInt())){
					ans = false;
					break;
				}
				n.removeRightDigit();
			}	
		}
		if(ans){
			cout << i << endl;
			answer += i;
		}
	}
	cout << answer << endl;
	return 0;
}
size_t Num::dequeSize(){
	return digits.size();
}
int Num::dequeToInt(){
	int factor = 1;
	int ans = 0;
	for(auto i : digits){
		ans += (i*factor);
		factor *= 10;
	}
	return ans;
}
void Num::removeLeftDigit(){
	digits.pop_back();
}
void Num::removeRightDigit(){
	digits.pop_front();
}
void Num::resetDeque(){
	int x = n;
	digits.clear();
	while(x > 0){
		digits.push_back(x%10);
		x /= 10;
	}
}
bool is_prime(int n){
	bool ans = true;
	if(n == 0 or n == 1){
		return false;
	}
	for( int i = 2 ; i*i <= n ; i++){
		if(n%i == 0){
			ans = false;
			break;
		}
	}
	return ans;
}
