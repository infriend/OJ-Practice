#include<iostream>
#include<algorithm>
using namespace std;

int board[510];
int t, k, n;

int countPainters(int cap){
    int sum = 0;
    int painters = 1;
    for (int i = 0; i < n; i++){
        sum += board[i];
        if (sum > cap){
            sum = board[i];
            painters += 1;
        }
    }
    return painters;
}

int search(int low, int high){
    while(low < high){
        int mid = (low + high) >> 1;
        int p_nums = countPainters(mid);
        if (p_nums > k){
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
        cin >> k >> n;
        int min_num = 0, max_num = 0;
        for (int j = 0; j < n; j++){
            cin >> board[j];
            max_num += board[j];
            if (board[j] > min_num) {
                min_num = board[j];
            }
        }   
        cout << search(min_num, max_num) << "\n"; 
    }

    return 0;
}