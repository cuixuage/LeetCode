/*
从边界开始所有能和‘O’链接的O不会被替换
其它的元素被替换为X
*/

class Solution{
public:
    void solve(vector<vector<char>>& board){
        if(board.size()==0) return;
        rowNum = board.size();
        colNum = board[0].size();
        
        for(int i=0;i<rowNum;i++){
            //检查第一列和最后一列
            check(board,i,0);
            if(colNum>1) check(board,i,colNum-1);
        } 
        for(int j=1;j<colNum-1;j++){
            //检查第一行和最后一行
            check(board,0,j);
            if(rowNum>1) check(board,rowNum-1,j);
        }
        
        for(int i=0;i<rowNum;i++){
            for(int j=0;j<colNum;j++)
                if(board[i][j]=='O') 
                    board[i][j]='X';
                else if(board[i][j]=='1') 
                    board[i][j]='O';
        }
    }

private:
    int rowNum;
    int colNum;
    void check(vector<vector<char>>& vec,int i,int j){
        //对于边界是'0'的元素 递归寻找所有相连的'O'
        if(vec[i][j]=='O'){
            vec[i][j]='1';
            if(i>1) check(vec,i-1,j);
            if(j>1) check(vec,i,j-1);
            if(i+1<rowNum) check(vec,i+1,j);
            if(j+1<colNum) check(vec,i,j+1);
        }
    }
}
