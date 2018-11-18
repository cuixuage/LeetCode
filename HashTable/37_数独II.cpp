/*
1.给出完整的数独解决方案
2.假设只有一个答案
*/

class Solution{
public:
    void solveSudoku(vector<vector<char>>& board){
        b = board;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] -'0' - 1;
                    int mapk = i/3*3 + j/3;
                    row[i][num] = col[j][num] = block[mapk][num] = 1;
                }
            }
        }
        Helper(0);
        //vector 是容器
        board = b;
    }
private:
    int row[9][9] = {0};
    int col[9][9] = {0};
    int block[9][9] = {0};
    vector<vector<char>> b;
    
    bool Helper(int ind){
        if(ind == 81) return true;
        int i = ind/9;
        int j = ind%9;  int num,k;
        if(b[i][j]!='.') return Helper(ind+1);
        else{
            for(char f='1'; f<='9'; f++){
                num = f-'1'; 
                k= i/3*3 + j/3;
                if(!row[i][num] && !col[j][num] && !block[k][num]){
                    b[i][j]= f;
                    row[i][num] = col[j][num] = block[k][num] = true;
                    if(Helper(ind+1)) return true;                
                    b[i][j]='.';
                    row[i][num] = col[j][num] = block[k][num] = false;
                }
            }
            return false;
        }
    }
}
