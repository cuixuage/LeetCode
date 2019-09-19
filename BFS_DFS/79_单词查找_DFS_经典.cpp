// 二维vector<char>相当于地图  只能从相邻的字母中构建单词
//同一个格子不能重复使用
/*
Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/


class Solution{
public:
    bool exist(vector<vector<char>>& board, string word){
        row = board.size();
        col = board[0].size();
        //对于每一个可能的起始点
        for(int x=0;x<row;x++){
            for(int y=0;y<col;y++){
                if(isFound(board,word.c_str(),x,y))
                    return true;
            }
        }
        return false;
    }

private:
    int row;
    int col;
     bool isFound(vector<vector<char>>& board, const char* w,int x,int y){
         //1. 先写return语句
         if(x<0||y<0||x>=row||y>=col||board[x][y]=='\0'||*w!=board[x][y])
            return false;
        if(*(w+1)=='\0')            //到达待查找的str的终点 True
            return true;
        //2. 再写回溯
        char tmp = board[x][y];
        board[x][y] = '\0';         //标记已经使用过  //相邻元素有一个能满足*(w+1)=='\0'即可
        if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
            return true;
        board[x][y] = tmp;          //回溯
        return false;
     }
}
