#include <iostream>
#include <cassert>
#include <string>
#include <ctime>

using namespace std;

int main(){
	clock_t start_s=clock();
	
	string h;
	for(int i = 0 ; i <= 1000000 ; i++){
		h += to_string(i);
	}

	int ans = 1, f = 1;
	for(int i = 0 ; i <= 6 ; i++){
		ans *= (int)h[f] - 48;
		f *= 10;
		cout << ans << endl;
	}

	clock_t stop_s=clock();
	cout << "time: " << static_cast<double>(stop_s-start_s)/static_cast<double>(CLOCKS_PER_SEC)<< endl;
	return 0;
}
