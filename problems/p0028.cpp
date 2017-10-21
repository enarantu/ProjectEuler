#include <iostream>
using namespace std;

void recurse(unsigned long long& a, unsigned long long& b, unsigned long long& c, unsigned long long& d, 
    unsigned long long& sum,unsigned long long& stage);
int main(){
    unsigned long long  a = 1, b = 1, c = 1, d = 1, sum = 1, gap = 2;
    while(gap < 1001){
        recurse(a,b,c,d,sum,gap);
    }
    cout << sum << endl;
    return 0;
}

void recurse(unsigned long long& a, unsigned long long& b, unsigned long long& c, unsigned long long& d, 
    unsigned long long& sum,unsigned long long& stage){
        a = d + stage;
        b = a + stage;
        c = b + stage;
        d = c + stage;
        stage += 2;
        sum += a;
        sum += b;
        sum += c;
        sum += d;
}