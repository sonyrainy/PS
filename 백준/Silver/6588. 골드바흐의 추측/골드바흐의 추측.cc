#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;
vector<bool> is_prime(MAX + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님
    for (int i = 2; i * i <= MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve(); // 소수를 미리 계산

    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        bool found = false;
        for (int i = 3; i <= n / 2; i += 2) {
            if (is_prime[i] && is_prime[n - i]) {
                cout << n << " = " << i << " + " << n - i << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}
