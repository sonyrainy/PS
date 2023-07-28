#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;

void binarySearch(int val, vector<int> &a) {
    int start = 0;
    int end = N - 1;
    while(start<=end){
        int mid = (start + end) / 2;
        if (val < a[mid]) {
            end = mid - 1;
        }
        else if (val > a[mid]) {
            start = mid + 1;
        }
        else {
            cout << 1 << "\n";
            return;
        }
    }
    cout << 0 << "\n";
    return;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int val;
        cin >> val;
        binarySearch(val, a);
    }
    return 0;
    

}