#include <iostream>

void Solve() {
    int X, Y;
    std::cin >> X >> Y;
    std::cout << "yes" << "\n";
}

void TC() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        Solve();
    }
}

int main() {
    TC();
}