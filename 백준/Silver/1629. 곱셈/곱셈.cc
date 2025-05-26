#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll POW(ll a, ll b, ll c){
  if(b==1) return a % c;
  
  // 나누기 2로 쪼개서 연산 줄이고,
  ll val = POW(a, b/2, c);
  
  // 그 값을 토대로 다시 곱하고 나눈다.
  val = val * val % c;
  
  // b가 2k로 표현되는 값이라면,
  if(b%2 == 0) return val;
  
  // 2k + 1로 표현된다면, 곱하고 % c
  return val * a % c;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a,b,c;
  cin >> a >> b >> c;
  cout << POW(a,b,c);
}