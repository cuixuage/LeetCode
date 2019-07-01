#include "func.h"
/*
m*n的棋盘,从左上到右下,一共有多少种走法？
（只能向下或者向右）
note: 棋盘某些位置有障碍物
*/

bool isObstacles(vector<vector<int>>& grid,int i,int j){
    return grid[i][j]==1?true:false;
}

int uniquePathsWithObstacles(vector<vector<int>>& grid){
    int row = grid.size();
    int column = grid[0].size();
    //case0 起始为障碍物
    if(grid[0][0]==1) return 0;
    //case1 只有一行或者一列 ,有障碍物则无法通过
    if(row==1 || column==1){
        for(int i=0;i<row;i++)
            for(int j=0;j<column;j++)
                if(isObstacles(grid,i,j)) return 0; 
        return 1;
    }
    //思路: grid[i][j]为障碍物,dp[i][j]=0
    //else dp[i][j] = dp[i-1][j] + dp[i][j-1]
    vector<vector<long long>> dp(row,vector<long long>(column,0));
    //case2 初始化第一行,第一列; 障碍物后面的格子无法达到
    for(int i=0;i<row;i++){
        if(!isObstacles(grid,i,0)) dp[i][0] = 1;
        else break;
    }
    for(int j=0;j<column;j++){
        if(!isObstacles(grid,0,j)) dp[0][j] = 1;
        else break;
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<column;j++){
            if(isObstacles(grid,i,j)) {dp[i][j]=0;continue;}
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[row-1][column-1];
}
