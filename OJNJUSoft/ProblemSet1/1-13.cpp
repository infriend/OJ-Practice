#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int a[110] = {0};

void print_set(int n, int k, int s){
    int temp[4] = {0};
    map<string, int> res_map;
    for (int i = 0; i < (1<<n); i++){
        int num = 0, kk = i;
        while(kk){
            kk = kk&(kk-1);
            num++;
        }
        int t_index = 0, res = 0;
        if(num == k){
            for(int j = 0; j < n; j++){
                if (i & (1<<j)){
                    temp[t_index++] = a[j];
                    res += a[j];
                }
            }
            if (res == s){
                sort(temp, temp+4);
                string res_str;
                for (int j = 0; j < 4; j++){
                    res_str += to_string(temp[j])+" ";
                }
                if(!res_map.count(res_str)){
                    for (int j = 0; j < 4; j++){
                        cout << temp[j] << " ";
                    }
                    cout << '$';
                    res_map[res_str] = 1;
                } else{
                    continue;
                }
            }
        }
        t_index = 0;
        res = 0;
    }
    cout << endl;
}

int main(){
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n >> k;
        for (int j = 0; j < n; j++){
            cin >> a[j];
        }
        print_set(n, 4, k);
    }

    return 0;
}