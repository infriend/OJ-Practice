//
// Created by infriend on 2022/2/3.
//
#include <iostream>
using namespace std;

long fastpow(int a, int n, int mod){
    long base = a;
    long res = 1;
    while(n){
        if(n & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        long a, b, c;
        cin >> a >> b >> c;
        cout << fastpow(a, b, c) << endl;
    }
    return 0;
}
