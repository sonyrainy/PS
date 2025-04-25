#include <iostream>
using namespace std;

int YY[12] = { 31, 29, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };
int NY[12] = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    int cnt = 0;
    cin >> n >> p;
    bool isY = false;
    if ((n % 4 == 0 && n % 100 != 0) ||( n % 400 == 0)) {
        isY = true;
    }
    else {
        isY = false;
    }

 
        for (int i = 0; i < 12; i++) {
            int last;
            if (isY == true) {
                last = YY[i];
                for (int j = 1; j < YY[i]; j++) {
                    if ((last--) - 28 > 0) {
                        cnt++;
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                last = NY[i];
                for (int j = 1; j < NY[i]; j++) {
                    if ((last--) - 28 > 0) {
                        cnt++;
                    }
                    else {
                        break;
                    }
                }
            }

        }
        cout << cnt;
    



    return 0;
}
