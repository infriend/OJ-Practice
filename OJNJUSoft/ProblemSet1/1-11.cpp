#include <bits/stdc++.h>
using namespace std;

struct student{
    int p, c, m;
    bool operator<(student s){
        return p-s.p < 0 || (p-s.p == 0 && c-s.c > 0) || (p-s.p == 0 && c-s.c == 0 && m - s.m < 0);
    }
};

int main(){
    int t, n;
    student s[10100];
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> s[j].p >> s[j].c >> s[j].m;
        }
        sort(s, s+n);
        for(int j = 0; j < n; j++){
            cout << s[j].p << " " << s[j].c << " " << s[j].m << endl;
        }
    }
    return 0;
}