#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> stair(303);

//최대값 넣을 벡터
vector<int> dp(303);
int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> stair[i];
    }


    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(dp[1] + stair[3], dp[0] + stair[2] + stair[3]);
    for (int i = 4; i <= N; i++) {
        
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
    }

    cout << dp[N];

    return 0;
}
