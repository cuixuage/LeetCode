/*
寻找最短距离
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
#include "func.h"
//dp[i][j] = std::max(dp[i-1][j]+nums[i][j],dp[i][j-1]+nums[i][j])
int minPathSum(vector<vector<int>>& grid){
    int row = grid.size();
    int column = grid[0].size();
    vector<vector<int>> dp(row,vector<int>(column,0));
    for(int i=0;i<row;i++){
        if(i==0) dp[i][0] = grid[i][0];
        else dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(int j=0;j<column;j++){
        if(j==0) dp[0][j] = grid[0][j];
        else dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<column;j++)
            dp[i][j] = std::min(dp[i-1][j]+grid[i][j],
                                dp[i][j-1]+grid[i][j]);
    }
    return dp[row-1][column-1];
}