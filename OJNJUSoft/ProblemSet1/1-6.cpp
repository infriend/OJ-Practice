#include<iostream>
using namespace std;

int t;
long long p;

long long sigma_n2(long long n){
    return n*(n+1)*(2*n+1)/6;
}

int bi_search(int low, int high){
    while (low < high){
        long long mid = (low + high) >> 1;
        long long temp = sigma_n2(mid);
        if (temp < p){
            low = mid+1;
        } else{
            high = mid;
        }
    }
    if (sigma_n2(low)>p) {
        low--;
    }
    return low;
}

int search(){
    int k = 1;
    while ((k * (k + 1) * (2 * k + 1))/6 <= p){
        k += 1;
    }
    return k-1;
}

int main(){
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> p;
        cout << search() << endl;
    }
    return 0;
}