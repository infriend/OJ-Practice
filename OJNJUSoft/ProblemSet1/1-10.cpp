#include<iostream>
using namespace std;

int a[55];
int t, n, m;

int countstudent(int page){
    int sum = 0;
    int students = 1;
    for (int i = 0; i < n; i++){
        sum += a[i];
        if (sum > page){
            sum = a[i];
            students += 1;
        }
    }
    return students;
}

int search(int low, int high){
    while (low < high){
        int mid = (low + high) >> 1;
        int p_nums = countstudent(mid);
        if (p_nums > m){
            low = mid + 1;
        } else{
            high = mid;
        }
    }
    return low;
}

int main(){
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        int min_num = 1, max_num = 0;
        for (int j = 0; j < n; j++){
            cin >> a[j];
            max_num += a[j];
        }
        cin >> m;
        if (m > n){
            cout << -1 << endl;
            continue;
        }
        int res = search(min_num, max_num);
        cout << res << endl;
    }
    return 0;
}