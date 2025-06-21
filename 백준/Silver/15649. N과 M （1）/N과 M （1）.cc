#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

// 현재 k개까지 수를 택했음.
void func(int k){

 // (base case) m개를 모두 택했으면
  if(k == m){
    for(int i = 0; i < m; i++){
     // arr에 기록해둔 수를 출력
      cout << arr[i] << " ";
    }
     cout<<"\n";
    return;
  }
  
	// 1부터 n까지의 수에 대해
  for(int i = 1; i <= n; i++){
   
  // 아직 i가 사용되지 않았으면
    if(!isused[i]){
    
	    // k번째 수를 i로 정함 
      arr[k] = i; 
      
      // i를 사용되었다고 표시
      isused[i] = 1; 
      
      // 다음 수를 정하러 한 단계 더 들어감
      func(k+1); 
      
      // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
      isused[i] = 0; 
      
      // +) arr는 0으로 초기화하지 않아도 되는데,
      // 어차피 값이 새로 덮이기 때문이다.
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}