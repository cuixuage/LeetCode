/*
回溯  
上下左右移动 & 不能回到已经过位置 & 限制格子位置
*/
#include "func.h"
// 0. check移动位置是否有效
int getDigitSum(int num){
    int sum = 0;
    while(num){
        sum += num%10;
        num /= 10;
    }
    return sum;
}
bool check(int threshold,int rows, int cols, int row, int col, vector<vector<bool>>& visited){
    if(row >= 0 && row < rows && col >= 0 && col < cols &&
        (getDigitSum(row) + getDigitSum(col) <= threshold ) &&
        visited[row][col]==false)
        return true;
    return false;    
}
//1. 回溯计算路径
int movingCore(int threshold,vector<vector<bool>>& visited,int row, int col){
    int rows = visited.size();
    int cols = visited[0].size();
    int count = 0;
    if(check(threshold,rows,cols,row,col,visited)){
        visited[row][col] = true;         //在check内部  不需要回溯
        count = 1 + movingCore(threshold,visited,row-1,col) +
                movingCore(threshold,visited,row,col-1) +
                movingCore(threshold,visited,row+1,col) +
                movingCore(threshold,visited,row,col+1); 
    }
    return count;
}

int movingCount(int threshold, int rows, int cols){
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    int count = movingCore(threshold,visited,0,0);
    return count;
}