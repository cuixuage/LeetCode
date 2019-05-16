/*
二维矩阵中,由1构成的最大正方形
区别: 由1构成的"小岛"数目的题目

DP[i][j]代表以当前点作为右下角的正方形的size大小
e.g.  
当dp[i][j]为数字0时,其能构成的正方形size=0
当dp[i][j]为数字1时, 作为右下角size= min{dp[i-1][j-1], dp[i-1][j],dp[i][j-1]} + 1
*/

#include"func.h"
int maximalSquare(vector<vector<char>>& matrix){
    if(matrix.empty()) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int maxSquare = 0;
    vector<vector<int>> dp(row, vector<int>(col,0));
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            if(i==0 || j==0 || matrix[i][j]=='0')
                dp[i][j] = matrix[i][j] - '0';
            else
                dp[i][j] = std::min(dp[i-1][j-1],std::min(dp[i-1][j],dp[i][j-1])) + 1;      //要理解
            maxSquare = std::max(dp[i][j],maxSquare);
        }
    }
    return maxSquare*maxSquare;
}