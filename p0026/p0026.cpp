#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int findLen(int i);
bool duplicate(vector<pair<int,int>>::iterator bIt, vector<pair<int,int>>::iterator eIt, int x);

int main(){
	int max = 0;
	for(int i = 1; i <= 1000; i++){
		int length = findLen(i);
		if(length > max){
			max = length;
		}
	}
	cout << max << endl;
	return 0;
}
int findLen(int i){
	vector<pair<int,int>> digits;
	int x = 1;
	do{ 
		int count=0;
		while(x != 0 and x < i){
			count++;
			x *= 10;
		}
		digits.push_back(pair<int,int>(x,count));
		x %= i;
	}
	while(!duplicate(digits.begin(),digits.end()-1,digits.back().first));
	auto it = digits.end() - 1;
	auto itx = it - 1;
	int count = it->second;
	while ( (*itx).first != (*it).first){
		itx--;
		count += itx->second;
	}
	itx++;
	count -= itx->second;
	count += 1;
	return count;
}
bool duplicate(vector<pair<int,int>>::iterator bIt, vector<pair<int,int>>::iterator eIt, int x){
	for(auto it = bIt; it != eIt; it++){
		if(it->first == x ){
			return true;
		}
	}
	return false;
}
