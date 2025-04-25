#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<string> toppings(n);
    
    for (int i = 0; i < n; i++) {
        cin >> toppings[i];
    }

    set<string> cheeseToppings;

    for (int i = 0; i < n; i++) {
        if (toppings[i].size() >= 6 && toppings[i].substr(toppings[i].size() - 6) == "Cheese") {
            cheeseToppings.insert(toppings[i]);
        }
    }

 
    if (cheeseToppings.size() >= 4) {
        cout << "yummy" << endl;
    } else {
        cout << "sad" << endl;
    }

    return 0;
}
