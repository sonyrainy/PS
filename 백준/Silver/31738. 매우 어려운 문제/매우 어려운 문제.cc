#include <bits/stdc++.h>

using namespace std;



int main()
{
    long long n, m;
    cin >> n >> m;
    long long k = 1;
    if (n >= m) {
        cout << 0;
        return 0;
    }
    for (long long i = 1; i <= n; i++) {
        k = (k * i) % m;
    }

    cout << k % m;

    return 0;
}