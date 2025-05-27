#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
    // Base Case: n=1일 때, 2x2 배열을 처리
    if (n == 1) {
        // 2x2 배열의 Z-형 순서는:
        // 0 1
        // 2 3
        if (r == 0 && c == 0) return 0;
        if (r == 0 && c == 1) return 1;
        if (r == 1 && c == 0) return 2;
        
        // r == 1, c == 1일 때
        return 3;  
    }

    // n > 1일 때 배열을 4개의 작은 배열로 나누기
    int half = 1 << (n - 1);  // 2^(n-1)
    
    // 첫 번째 사분면
    if (r < half && c < half) return func(n - 1, r, c);
    // 두 번째 사분면
    if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
    // 세 번째 사분면
    if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
    // 네 번째 사분면
    return 3 * half * half + func(n - 1, r - half, c - half);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c;
    cin >> n >> r >> c;
    
    cout << func(n, r, c) << endl;
    return 0;
}
