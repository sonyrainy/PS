#include <bits/stdc++.h>
using namespace std;

vector<string> keyboard(4);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    

    int x, y, direct;
    x = 1; 
    y = 1;

    int dx, dy;
    for (int i = 0; i < m; ++i) {
        cin >> dx >> dy >> direct;
        if (direct == 1) {          
            if (x >= dx) x = dx - 1;
            y = dy;
        }
        else if (direct == 2) {   
            if (x >= dx) x = dx - 1;
            if (y <= dy) y = dy + 1; 
        }
        else if (direct == 3) {      
            x = dx;
            if (y <= dy) y = dy + 1;
        }
        else if (direct == 4) {      
            if (x <= dx) x = dx + 1;
            if (y <= dy) y = dy + 1;
        }
        else if (direct == 5) {   
            if (x <= dx) x = dx + 1;
            y = dy;
        }
        else if (direct == 6) {    
            if (x <= dx) x = dx + 1;
            if (y >= dy) y = dy - 1; 
        }
        else if (direct == 7) {   
            x = dx;
            if (y >= dy) y = dy - 1; 
        }
        else {                   
            if (x >= dx) x = dx - 1;
            if (y >= dy) y = dy - 1;
        }
    }

    cout << x << " " << y << "\n";
    return 0;
}
