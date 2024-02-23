#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt;

void change(string str) {
  vector<char> strNew;
  cnt = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '@') {
      strNew.push_back('a');
      cnt++;
    } else if (str[i] == '[') {
      strNew.push_back('c');
      cnt++;
    } else if (str[i] == '!') {
      strNew.push_back('i');
      cnt++;
    } else if (str[i] == ';') {
      strNew.push_back('j');
      cnt++;
    } else if (str[i] == '^') {
      strNew.push_back('n');
      cnt++;
    } else if (str[i] == '0') {
      strNew.push_back('o');
      cnt++;
    } else if (str[i] == '7') {
      strNew.push_back('t');
      cnt++;
    } else if (str[i] == '\\') {
      if (str[i + 1] == '\'') {
        strNew.push_back('v');
        i += 1;
        cnt++;
      } else if (str[i + 1] == '\\' && str[i + 2] == '\'') {
        strNew.push_back('w');
        i += 2;
        cnt++;
      } else {
        strNew.push_back(str[i]);
      }
    } else {
      strNew.push_back(str[i]);
    }
  }
  if (cnt >= strNew.size() / 2.0) {
    cout << "I don't understand";
  } else {
    for (int i = 0; i < strNew.size(); i++) {
      cout << strNew[i];
    }
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string str;
    cnt = 0;
    cin >> str;
    change(str);
  }
  return 0;
}
