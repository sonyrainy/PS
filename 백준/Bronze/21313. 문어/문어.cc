#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;

    cin >> n;

    int a = n % 2 ? n - 1 : n;
    for (int i = 0; i < a; i++)
    {
        if (i % 2)
        {
            cout << "2 ";
        }
        else cout << "1 ";
    }

    if (n % 2)
    {
        cout << "3";
    }

    return 0;
}