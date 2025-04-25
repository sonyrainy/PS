#include <iostream>
using namespace std;

char zArr[12] = { 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'A', 'B', 'C', 'D','E' };
int gArr[10] = { 9,0,1,2,3,4,5,6,7,8};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int diff = n - 2013;

    cout << zArr[(diff % 12 + 12)%12];
    cout << gArr[(diff % 10 + 10)%10];

    return 0;
}
