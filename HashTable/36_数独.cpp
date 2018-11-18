/*
每行 每列 每3*3区域不能有重复的元素填充
注意: 9*9棋盘 只需要判断当前存在的数字是否有效   (而非填充完整的数独)
*/

// used矩阵 行:规则对应到同一行  列:[0,..,9]已经使用的标志
//used1  检查board[i][j]是否在i行 出现过
//used2  ~是否在j列出现过
//used3  其中mapk使得同一个3*3的区域在同一行上  e.g.(6,7)(6,8)(7,7)都在used3最后一行
bool isVaildSudoku(vector<vector<char>>& board){
    int used1[9][9] = {0};
    int used2[9][9] = {0};
    int used3[9][9] = {0};
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board[i].size();++j){
            if(board[i][j] != '.'){
                int num = board[i][j]-'0'-1;
                int mapk = (i/3)*3 + j/3;
                if(used1[i][num] || used2[j][num] || used3[mapk][num])
                    return false;   //已经被占据
                    
                used1[i][num] = used2[j][num] = used3[mapk][num] = 1;    
            }
        }
    }
    return true;
}
