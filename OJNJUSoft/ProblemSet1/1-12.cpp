//
// Created by infriend on 2022/2/21.
//
#include <bits/stdc++.h>
using namespace std;

struct partytime{
    int time;
    char type;
    bool operator<(partytime p){
        return time-p.time < 0 || (time-p.time == 0 && type > p.type);
    }
};

int main(){
    int t, n;
    partytime parray[10010];
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> parray[j].time;
            parray[j].type = 's';
        }
        for (int j = n; j < n+n; j++){
            cin >> parray[j].time;
            parray[j].type = 'e';
        }
        sort(parray,parray+n+n);
        int guests = 0, position = 0, max_guests = 0;
        int last_time = 0, last_pos = 0;
        for (int j = 0; j < n+n; j++){
            if (last_time != parray[j].time || parray[j].type=='e'){
                if (guests > max_guests){
                    max_guests = guests;
                    position = last_pos;
                }
                last_time = parray[j].time;
                last_pos = j;
                if(parray[j].type=='e'){
                    guests--;
                }
            }
            if(parray[j].type=='s'){
                guests++;
            }
        }
        if (guests > max_guests){
            max_guests = guests;
            position = last_pos;
        }
        cout << max_guests << " " << parray[position].time << endl;
    }
    return 0;
}