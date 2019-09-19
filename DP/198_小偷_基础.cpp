/*
不能连续的偷窃, 最大的偷窃价值？
dp[i] = dp[i-1]
      = dp[i-2] + arr[i]
dp[0] = arr[0]
dp[1] = max(arr[0],arr[1])
*/
#include "func.h"
int rob(vector<int>& arr) {
    if(arr.size()==0) return 0;
    if(arr.size()==1) return arr[0];
    vector<int> dp(arr.size(),0);
    dp[0] = arr[0];
    dp[1] = std::max(arr[0],arr[1]);
    for(int i=2;i<arr.size();i++){
        dp[i] = std::max(dp[i-1], dp[i-2]+arr[i]);
    }
    return dp[arr.size()-1];
}