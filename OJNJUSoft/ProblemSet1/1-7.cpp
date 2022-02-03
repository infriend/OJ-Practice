//
// Created by infriend on 2022/2/3.
//
#include <iostream>
#include <algorithm>
using namespace std;

int buf[100000];

bool cmp(int a, int b){
    if (a < b) return true;
    else return false;
}

int pow(int a, int n){
    int res = 1;
    for (int i = 0; i < n; i++){
        res *= a;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> buf[j];
        }

        int pow_n = 0, count = 0;
        int last_n;

        while (count < n){
            int position = pow(2, pow_n)+count;
            sort(&buf[count], &buf[position], cmp);
            last_n = buf[count];
            cout << last_n;
            for (int j = count+1; j < position; j++){
                if (last_n == buf[j]) continue;
                else cout << buf[j];
            }
            cout << endl;
            count = position;
            pow_n += 1;
        }
    }

    return 0;
}

