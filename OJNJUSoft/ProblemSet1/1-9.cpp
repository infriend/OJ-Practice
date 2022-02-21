//
// Created by infriend on 2022/2/19.
//

// This program would get runtime error in OJ
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

int sgn(double x){
    if(fabs(x) < eps) return 0;
    else return x<0 ? -1:1;
}

struct Point{
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}
    Point operator+ (Point B){return Point(x+B.x, y+B.y);}
    Point operator- (Point B){return Point(x-B.x, y-B.y);}
    bool operator== (Point B){return sgn(x-B.x) == 0 && sgn(y-B.y) == 0;}
    bool operator< (Point B){
        return sgn(x-B.x) < 0 || (sgn(x-B.x) == 0 && sgn(y-B.y) < 0);
    }
};
typedef Point Vector;
double Cross(Vector A, Vector B){return A.x*B.y- A.y*B.x;}
double Distance(Point A, Point B){return hypot(A.x-B.x, A.y-B.y);}
int Convex_hull(Point *p, int n, Point *ch){
    sort(p, p+n);
    n = unique(p, p+n) - p;
    int v = 0;
    for (int i = 0;i < n; i++){
        while(v > 1 && sgn(Cross(ch[v-1] - ch[v-2], p[i] - ch[v-2])) <= 0){
            v--;
        }
        ch[v++] = p[i];
    }
    int j = v;
    for (int i = n-2; i >= 0; i--){
        while(v>j && sgn(Cross(ch[v-1]-ch[v-2], p[i]-ch[v-2])) <= 0){
            v--;
        }
        ch[v++] = p[i];
    }
    if(n > 1) v--;
    return v;
}

int main(){
    int t, n;
    Point p[104], ch[104];
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> p[j].x >> p[j].y;
        }
        int v = Convex_hull(p, n, ch);
        if (v < 3){
            cout << -1 << endl;
        } else{
            sort(ch, ch+v);
            for (int j = 0; j < n; j++){
                if (j == n-1){
                    cout << ch[j].x << " " << ch[j].y << endl;
                } else{
                    cout << ch[j].x << " " << ch[j].y << ",";
                }
            }
        }
    }

    return 0;
}
