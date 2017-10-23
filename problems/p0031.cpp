#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

#define NUMBER_OF_COINS	8
#define TARGET_COIN_SUM 200

using namespace std;

int dynamic_computation(int** dp,  int target, int coins,vector<int>& coin_values);

int main(){
						   //0, 1, 2,  3,  4,  5,   6,   7 ;
	vector<int> coin_val = { 1, 2, 5, 10, 20, 50, 100, 200};
	cout << "Coin values initialized" << endl;
	for(auto i : coin_val){
		cout << setw(5) << i;
	}
	cout << endl;

	int** dp = new int* [TARGET_COIN_SUM];
	for(int i = 0 ; i < TARGET_COIN_SUM ; i++){
		dp[i] = new int[NUMBER_OF_COINS];
	}

	for(int i = 0 ; i < TARGET_COIN_SUM; i++){
		for(int j = 0 ; j < NUMBER_OF_COINS; j++){
			dp[i][j] = -1;
		}
	}

	cout << "dp array initialized" << endl;
	for(int i = 0 ; i < TARGET_COIN_SUM ; i++){
		for(int j = 0 ; j < NUMBER_OF_COINS; j++){
			cout << setw(6) << dp[i][j];
		}
		cout << endl;
	}

	cout << dynamic_computation(dp,TARGET_COIN_SUM,NUMBER_OF_COINS,coin_val) << endl;
	
	cout << "dp array at the end" << endl;
	for(int i = 0 ; i < TARGET_COIN_SUM ; i++){
		for(int j = 0 ; j < NUMBER_OF_COINS; j++){
			cout << setw(6) << dp[i][j];
		}
		cout << endl;
	}
	for(int i = 0 ; i < TARGET_COIN_SUM ; i++){
		delete [] dp[i];
	}
	delete [] dp;

	return 0;
}

int dynamic_computation(int** dp, int target, int coins, vector<int>& coin_values){
	if( target < 0 ){
		return 0;
	}
	else if( target == 0 ){
		return 1;
	}
	else if( coins <= 0 ){ 
		return 0;
	}
	else if( dp[target-1][coins-1] > -1 ){
		return dp[target-1][coins-1];
	}
	else{
		long long answer = 0;
        for(int i = 0; i <= target ; i += coin_values[coins-1]){
            answer += dynamic_computation(dp,target-i,coins-1,coin_values);
        }
        dp[target-1][coins-1] = answer;
        return answer;
	}
}